const execa = require('execa');
const ExprStream = require('./exprstream');
const chrono = require('./chrono');

const testBistromatic = function (expr, base, options) {
    return new Promise((fulfill, reject) => {
        let prc = execa('../calc', [base.chars, (options && options.operators) || '()+-*/%', expr.length],
            {reject: false});
        let time = chrono();
        prc.then(result => {
            /*
            // Temp remove debug from calc
            let n = result.stdout.lastIndexOf('\n');
            if (n !== -1) {
                result.stdout = result.stdout.substr(n + 1);
            }
            */
            let divideByZero = false;
            if (result.code !== 0) {
                if (options && options.checkDivideByZero === true) {
                    result.stdout = 'divide by zero';
                    divideByZero = true;
                } else {
                    let e = new Error('Invalid exit status: ' + (result.code || result.signal) +
                        (result.stdout.length > 0 ? '\n' + result.stdout : ''));
                    e.code = result.code;
                    e.stdout = result.stdout;
                    return reject(e);
                }
            }
            return fulfill({
                result: result.stdout,
                divideByZero: divideByZero,
                time: time.end(),
            });
        }).catch(reject);
        if (expr instanceof ExprStream) {
            expr.write(prc.stdin).then(() => prc.stdin.end());
        } else {
            prc.stdin.write(expr, 'ascii', () => prc.stdin.end());
        }
    });
};

const testBC = function (expr, base) {
    return new Promise((fulfill, reject) => {
        let prc = execa('bc', ['-q'], {reject: false, env: {BC_LINE_LENGTH: 0}});
        let time = chrono();
        prc.then(result => {
            let divideByZero = false;
            if (result.stdout === '') {
                if (result.stderr.indexOf(': Divide by zero') !== -1
                    || result.stderr.indexOf(': Modulo by zero') !== -1) {
                    result.stdout = 'divide by zero';
                    divideByZero = true;
                } else {
                    let e = new Error('bc error: ' + (result.signal ? result.signal + ' ' : '') + result.stderr);
                    e.code = result.code;
                    e.stdout = result.stderr;
                    return reject(e);
                }
            }
            return fulfill({
                result: result.stdout,
                divideByZero: divideByZero,
                time: time.end(),
            });
        }).catch(reject);
        let endStream = () => prc.stdin.write('\n', 'ascii', () => prc.stdin.end());
        prc.stdin.write('obase=' + base.size + ';ibase=' + base.size + ';', 'ascii', () => {
            if (expr instanceof ExprStream) {
                expr.write(prc.stdin).then(endStream);
            } else {
                prc.stdin.write(expr, 'ascii', endStream);
            }
        });
    });
};

module.exports = {
    bistromatic: testBistromatic,
    bc: testBC,
};
