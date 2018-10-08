const createBase = function (name, base) {
    if (base === undefined) {
        base = name;
        name = 'custom';
    }
    return {
        name: name,
        size: base.length,
        chars: base,
    };
};

let bases = {
    BIN: createBase('bin', '01'),
    OCT: createBase('oct', '01234567'),
    DEC: createBase('dec', '0123456789'),
    HEX: createBase('hex', '0123456789ABCDEF'),
};

bases.create = createBase;

bases.createLegacy = function (len) {
    switch (len) {
        case bases.BIN.size:
            return bases.BIN;
        case bases.OCT.size:
            return bases.OCT;
        case bases.DEC.size:
            return bases.DEC;
        case bases.HEX.size:
            return bases.HEX;
        default:
            return bases.create('custom' + len, '0123456789ABCDEF'.substr(0, len));
    }
};

module.exports = bases;
