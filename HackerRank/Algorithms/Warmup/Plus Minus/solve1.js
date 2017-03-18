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
    arr = readLine().split(' ');
    arr = arr.map(Number);

    var cnts = [0, 0, 0];
    arr.forEach(function(x) { 
        if (x > 0) ++cnts[0];
        else if (x < 0) ++cnts[1];
        else ++cnts[2];
    });
    var total = arr.length;
    console.log(cnts[0]/total + '\n' + cnts[1]/total + '\n' + cnts[2]/total);
}

