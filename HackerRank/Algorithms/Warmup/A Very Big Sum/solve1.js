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
    var n = parseInt(readLine());
    arr = readLine().split(' ').map(Number);
    arr = arr.map(Number);
    
    var sum = 0;
    // http://stackoverflow.com/questions/9329446/for-each-over-an-array-in-javascript
    arr.forEach(function(x) { sum += x; })
    console.log(sum);
}

