const bases = require('./bases');
const unit = require('./unit');
const randomTests = require('./tests/random.js');

let commands = {
    'manual': function (argv) {
        return new Promise(async (fulfill, reject) => {
            try {
                if (argv._.length === 0) {
                    return reject(new Error('You must specify at least one expression to test.'));
                }
                let result = true;
                unit.printCategory('manual');
                for (let expr of argv._) {
                    if (!await unit.print(unit.bcComparison, expr, bases.DEC)) {
                        result = false;
                    }
                }
                console.log('');
                return fulfill(result);
            } catch (e) {
                return reject(e);
            }
        });
    },

    'stackbreak': function (argv) {
        return new Promise(async (fulfill, reject) => {
            unit.printCategory('stackbreak');
            let breakStream = new (require('./tests/stackbreakstream.js'));
            let result = await unit.print(unit.assert, breakStream, bases.DEC, breakStream.result);
            console.log('');
            return result;
        });
    },

    'random': function (argv) {
        return new Promise(async (fulfill, reject) => {
            unit.printCategory('random');
            let result = randomTests.loopTests(argv, randomTests.genRandom);
            console.log('');
            return result;
        });
    }
};

const registerAssertTests = function (group, tests) {
    let groupCommands = [];
    for (let name in tests) {
        if (tests.hasOwnProperty(name)) {
            commands[group + '-' + name] = function (argv) {
                return new Promise(async (fulfill, reject) => {
                    try {
                        let result = true;
                        unit.printCategory(group + '-' + name);
                        for (let test of tests[name]) {
                            if (!await unit.print(unit.assert, test[0], test[2] || bases.DEC, test[1], test[3])) {
                                result = false;
                            }
                        }
                        console.log('');
                        return fulfill(result);
                    } catch (e) {
                        return reject(e);
                    }
                });
            };
            groupCommands.push(commands[group + '-' + name]);
        }
    }
    commands[group] = function (argv) {
        return new Promise(async (fulfill, reject) => {
            let result = true;
            for (let groupCommand of groupCommands) {
                if (!await groupCommand(argv)) {
                    result = false;
                }
            }
            return fulfill(result);
        });
    };
};

registerAssertTests('simple', require('./tests/simples'));

module.exports = commands;
