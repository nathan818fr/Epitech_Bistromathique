const fs = require('fs');
const ExprStream = require('../exprstream.js');

const STACKBREAK_CHUNK_SIZE = 2000;
const STACKBREAK_CHUNK_REPEAT = 1000;
// '1+(' is repeated (STACKBREAK_CHUNK_SIZE*STACKBREAK_CHUNK_REPEAT) times!

let chunkStart = '';
let chunkMiddle = '1+1';
let chunkEnd = '';
for (let i = 0; i < STACKBREAK_CHUNK_SIZE; i++) {
    chunkStart += '1+(';
    chunkEnd += ')';
}
const totalResult = '' + (STACKBREAK_CHUNK_REPEAT * STACKBREAK_CHUNK_SIZE + 2);
const totalLen = STACKBREAK_CHUNK_REPEAT * (chunkStart.length + chunkEnd.length) + chunkMiddle.length;

const promiseWrite = function (stream, data, encoding) {
    return new Promise((fulfill, reject) => {
        stream.write(data, encoding, () => fulfill());
    });
};

class StackBreakStream extends ExprStream {
    get result() {
        return totalResult;
    }

    get length() {
        return totalLen;
    }

    write(dest) {
        return new Promise(async (fulfill, reject) => {
            for (let i = 0; i < STACKBREAK_CHUNK_REPEAT; i++) {
                await promiseWrite(dest, chunkStart, 'ascii');
            }
            await promiseWrite(dest, chunkMiddle, 'ascii');
            for (let i = 0; i < STACKBREAK_CHUNK_REPEAT; i++) {
                await promiseWrite(dest, chunkEnd, 'ascii');
            }
            return fulfill();
        });
    }
}

module.exports = StackBreakStream;
