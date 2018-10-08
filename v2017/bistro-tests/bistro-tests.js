#!/usr/bin/env node
const figlet = require('figlet');
const chalk = require('chalk');
const minimist = require('minimist');
const commands = require('./lib/commands');

const printUsage = function (detailed) {
    console.log(' Usage: ./bistro-tests.js COMMAND [OPTIONS] [PARAMS...]');
    console.log('');
    console.log(' Commands:');
    console.log('   manual          Enter a legacy expression manually');
    console.log('   simple          All the simple tests');
    console.log('    simple-calc     Simple infinite calculations tests');
    console.log('    simple-eval     Simple evaluation tests');
    console.log('    simple-errors   Test some expressions that must fail');
    console.log('    simple-pdf      Tests from Epitech PDF');
    console.log('   random          Generate random expression and check');
    console.log('   stackbreak      Break stack limits');
    console.log('');
    console.log(' Options:');
    console.log('  -f, --full          Display full expressions and results for each tests');
    console.log('  -t, --time          Display tested programs execution time');
    console.log('  -w, --wait MILLIS   Wait MILLIS milliseconds between each tests');
    console.log('');
};

const execCommand = async function (command, argv) {
    if (commands.hasOwnProperty(command)) {
        return await commands[command](argv);
    }
    throw new Error('Unknown command: ' + command);
};

(async () => {
    let exitCode = 0;
    try {
        console.log(chalk.red(figlet.textSync('Bistro-matic', {font: 'Standard'})));
        console.log(chalk.magenta('  The Bistro-matic testing program.'));
        console.log('');

        let argv = minimist(process.argv.slice(2));
        let command = argv._[0];
        if (argv.h || argv.help) {
            printUsage(true);
        } else if (!command) {
            printUsage();
        } else {
            global.PRINT_FULL_EXPRESSION = (argv.f || argv.full);
            global.SHOW_TIME = (argv.t || argv.time);
            global.WAIT_MS = argv.w || argv.wait;
            if (WAIT_MS !== undefined) {
                WAIT_MS = parseInt(WAIT_MS);
                if (isNaN(WAIT_MS) || WAIT_MS <= 0) {
                    throw new Error('wait argument must be a positive integer');
                }
            }

            argv._ = argv._.splice(1);
            if (!await execCommand(command, argv)) {
                console.log(chalk.red.bold('One or more errors occurred! (see above)'));
                exitCode = 1;
            }
        }

        process.exit(exitCode);
    } catch (e) {
        console.error('Fatal error: ' + e.message);
        process.exit(1);
    }
})();
