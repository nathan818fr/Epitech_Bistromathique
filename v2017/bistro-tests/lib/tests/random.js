const randomJs = require('random-js');
const bases = require('../bases');
const unit = require('../unit');

// Config
const NB_MIN_LEN = 1;
const NB_MAX_LEN = 30;
const MAX_NB_COUNT = 15000;
const BRACKET_OPEN_PROB = 0.25;
const BRACKET_CLOSE_PROB = BRACKET_OPEN_PROB;
const BRACKET_NEG_PROB = 0.2;
const OPERATORS = [
    ['+', 1],
    ['-', 1],
    ['*', 1],
    ['/', 0.05],
    ['%', 0.05],
];

// Init
{
    let opTotal = 0;
    for (let o of OPERATORS) {
        opTotal += o[1];
    }
    let opCur = 0;
    for (let o of OPERATORS) {
        opCur += o[1] / opTotal;
        o[1] = opCur;
    }
}

const mt19937 = randomJs.engines.mt19937();
mt19937.autoSeed();

// Utils
const randInt = function (min, max) {
    return randomJs.integer(min, max)(mt19937);
};

const randZeroToOneExcl = function () {
    return randomJs.real(0, 1, false)(mt19937);
};

const randBool = function (percent) {
    return randomJs.bool(percent)(mt19937);
};

const randBase = function () {
    return bases.createLegacy(randInt(3, 16));
};

const randNumber = function (base, minLen, maxLen, notStartWithZero) {
    let len = randInt(minLen, maxLen);
    let nb = '';
    for (let i = 0; i < len; i++) {
        nb += base.chars[randInt((i === 0 && notStartWithZero ? 1 : 0), base.size - 1)];
    }
    return nb;
};

// Generators
const genRandom = async function (testCount) {
    let base = (testCount % 3 === 0) ? bases.DEC : randBase();
    let nbCount;
    if (testCount * testCount * 2 > MAX_NB_COUNT) {
        nbCount = randInt(1, MAX_NB_COUNT);
    } else {
        nbCount = Math.min(testCount * testCount + randInt(0, testCount - 1), MAX_NB_COUNT);
    }
    let expr = '';
    let openBrackets = 0;
    for (let i = 0; i < nbCount; i++) {
        let currentOp = '';
        if (i !== 0) {
            // Add operator
            let opProb = randZeroToOneExcl();
            for (let o of OPERATORS) {
                if (opProb < o[1]) {
                    currentOp = o[0];
                    break;
                }
            }
            if (currentOp === '') {
                throw new Error('IMPOSSIBLE: No op');
            }
            expr += currentOp;
            if (currentOp !== '-' && randBool(BRACKET_NEG_PROB)) {
                expr += '-';
            }
        }

        while (randBool(BRACKET_OPEN_PROB)) {
            // Open bracket
            openBrackets++;
            if (currentOp === '' && randBool(BRACKET_NEG_PROB)) {
                expr += '-';
            }
            currentOp = '';
            expr += '(';
        }

        // Add number
        expr += randNumber(base, NB_MIN_LEN, NB_MAX_LEN, testCount % 10 < 8);

        while (openBrackets > 0 && randBool(BRACKET_CLOSE_PROB)) {
            // Close bracket
            openBrackets--;
            expr += ')';
        }
    }
    while (openBrackets > 0) {
        // Close all remaining brackets
        openBrackets--;
        expr += ')';
    }
    return {expr: expr, base: base};
};

module.exports = {
    loopTests: function (argv, randomFct) {
        return new Promise(async (fulfill, reject) => {
            let nb = 1;
            while (true) {
                let randExpr = await randomFct(nb++);
                if (!await unit.print(unit.bcComparison, randExpr.expr, randExpr.base)) {
                    return fulfill(false);
                }
            }
            return fulfill(true);
        });
    },

    genRandom: genRandom,
};