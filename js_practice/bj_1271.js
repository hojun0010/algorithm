let input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split(' ').map((e) => e.trim());

// console.log(input);
let n = BigInt(input[0]);
let m = BigInt(input[1]);   
// 1 <= m <= n <= 10^1000
if(n%m !== 0){
    k = n%m;
    n -= k;
    console.log((n/m).toString());
    console.log(k.toString());
}
else{
    console.log((n/m).toString());
}