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

function score(A, B) {
    return (A[0] > B[0]) + (A[1] > B[1]) + (A[2] > B[2]);
}

function main() {
    var A = readLine().split(' ').map(Number);
    var B = readLine().split(' ').map(Number);
    console.log(score(A, B), score(B, A));
}

