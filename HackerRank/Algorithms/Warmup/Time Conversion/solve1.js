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
    var time = readLine();
    // https://developer.mozilla.org/zh-TW/docs/Web/JavaScript/Reference/Global_Objects/String/endsWith
    var isAm = time.endsWith("AM");
    time = time.substr(0, time.length-2);
    var [h, m, s] = time.split(':').map(Number);
    h %= 12;
    h += (isAm) ? 0 : 12;

    // http://stackoverflow.com/questions/2998784/how-to-output-integers-with-leading-zeros-in-javascript
    function fillZero(num) {
        return ('00' + num.toString()).slice(-2);
    }
    
    console.log(fillZero(h) + ":" + fillZero(m) + ":" + fillZero(s));
}

