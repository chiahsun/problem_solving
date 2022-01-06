var params = readLine()!.split(separator: " ")
var G = Int(params[2])!
let T = readLine()!.split(separator: " ").map { Int($0)! }
var A = readLine()!.split(separator: " ").map { Int($0)! }
var D = 0
for i in 1..<T.count { 
    D = max((T[i] - T[i-1]), D)
}

var ans = 0
for a in A where a <= D { ans += 1 }
print(ans)