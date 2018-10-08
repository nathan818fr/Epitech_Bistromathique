const fs = require('fs-extra');
const chalk = require('chalk');
const legacyPrograms = require('./legacyPrograms');

const SHORT_EXPR_LEN = 30;
const SHORT_RES_LEN = 30;

const shortExpr = function (expr, base) {
    if (typeof expr === 'string') {
        if (expr.length > SHORT_EXPR_LEN) {
            expr = expr.substr(0, SHORT_EXPR_LEN) + '...(+' + (expr.length - SHORT_EXPR_LEN) + 'chars)';
        }
        return '[' + base.name + '] ' + expr;
    }
    return '<stream>(length: ' + expr.length + ')';
};

const shortRes = function (res) {
    if (res.length > SHORT_RES_LEN) {
        res = res.substr(0, SHORT_RES_LEN) + '...(+' + (res.length - SHORT_RES_LEN) + 'chars)';
    }
    return res;
};

const flAppend = function (str, append) {
    if (str.indexOf('\n') === -1) {
        return str + append;
    }
    return str.replace('\n', append + '\n');
};

const nlsp = function (sp, str) {
    let spaces = '';
    for (let i = 0; i < sp; i++) {
        spaces += ' ';
    }
    return str.replace(/\n/g, '\n' + spaces);
};

module.exports = {
    printCategory: function (name) {
        console.log(' • ' + chalk.white.bold(name) + ':');
    },

    print: function (unitFct, expr, base, _a, _b, _c) {
        return new Promise(async (fulfill, reject) => {
            let printFullExpression = () => {
                console.log('');
                console.log('Full expression: (' + base.name + ' ' + base.chars + ')');
                if (typeof expr === 'string') {
                    console.log(expr);
                } else {
                    console.log('<stream>(unable to display)');
                }
            };
            if (PRINT_FULL_EXPRESSION) {
                printFullExpression();
            }
            unitFct(expr, base, _a, _b, _c).then(res => {
                if (PRINT_FULL_EXPRESSION) {
                    console.log('\nResult:\n' + res.result + '\n');
                }
                console.log('  ' + chalk.green('✔ ' + res.message)
                    + ' ' + chalk.gray(shortExpr(expr, base) + ' = ' + shortRes(res.result)));
                if (SHOW_TIME) {
                    for (let programName in res.programs) {
                        if (res.programs.hasOwnProperty(programName)) {
                            let program = res.programs[programName];
                            console.log('     ' + programName + ': ' + program.time);
                        }
                    }
                    console.log('');
                }
                if (WAIT_MS) {
                    setTimeout(() => fulfill(res), WAIT_MS);
                } else {
                    return fulfill(res);
                }
            }).catch(async (err) => {
                try {
                    await fs.writeFile('failed-expr.txt', base.chars + '\n' + expr, 'utf8');
                } catch (e) {
                    console.error(e.message);
                }
                if (!PRINT_FULL_EXPRESSION) {
                    printFullExpression();
                }
                console.log('  ' + chalk.red('✘ ' + nlsp(5,
                    flAppend(err.message, ' ' + chalk.gray(shortExpr(expr, base))))));
                console.log('');
                return fulfill(false);
            });
        });
    },

    assert: function (expr, base, expectedResult, options) {
        return new Promise(async (fulfill, reject) => {
            let bistroRes;
            try {
                bistroRes = await legacyPrograms.bistromatic(expr, base, options);
            } catch (e) {
                if (expectedResult === null && e.stdout === 'syntax error') {
                    return fulfill({message: 'Failed successfully', result: e.stdout});
                }
                return reject(new Error('bistro-matic failed to compute expression.\n' + e.message));
            }
            if (bistroRes.result !== expectedResult) {
                return reject(new Error('Unexpected result!\nexpected: ' + expectedResult
                    + '\nbistro: ' + bistroRes.result));
            }
            return fulfill({
                message: 'Calculated correctly',
                result: bistroRes.result,
                programs: {
                    bistromatic: bistroRes,
                },
            });
        });
    },

    bcComparison: function (expr, base) {
        return new Promise(async (fulfill, reject) => {
            let bcRes;
            let bistroRes;
            try {
                bcRes = await legacyPrograms.bc(expr, base);
            } catch (e) {
                return reject(new Error('BC failed to compute expression. Details: ' + e.message));
            }
            try {
                bistroRes = await legacyPrograms.bistromatic(expr, base, {checkDivideByZero: bcRes.divideByZero});
            } catch (e) {
                return reject(new Error('bistro-matic failed to compute expression. Details: ' + e.message));
            }
            if (bistroRes.result !== bcRes.result) {
                return reject(new Error('Unexpected result!\nbc: ' + bcRes.result + '\nbistro: ' + bistroRes.result));
            }
            return fulfill({
                message: 'Calculated correctly',
                result: bistroRes.result,
                programs: {
                    bc: bcRes,
                    bistromatic: bistroRes,
                },
            });
        });
    },
};
