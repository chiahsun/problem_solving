process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var A = readLine().split(' ').map(Number);
    // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/Reduce
    var sum = A.reduce(function(acc, val) { return acc += val; }, 0);
    var max = A.reduce(function(acc, val) { return Math.max(acc, val); }, A[0]);
    var min = A.reduce(function(acc, val) { return Math.min(acc, val); }, A[0]);
    console.log(sum - max, sum - min);
}

