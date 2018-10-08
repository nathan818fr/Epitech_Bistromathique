module.exports = function () {
    return {
        startTime: process.hrtime(),
        endTime: null,
        end: function () {
            this.endTime = process.hrtime(this.startTime);
            return this.endTime[0] + 's ' + (this.endTime[1] / 1000000) + 'ms';
        },
    };
};