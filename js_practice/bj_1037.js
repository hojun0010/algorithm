const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

const n = Number(input[0]); // <50개
let real_measure = input[1].split(" ").map((e) => Number(e)); //진짜 약수 <= 1 000 000 -> result <= 2 000 000


real_measure.sort(function(a,b){
    return a-b; //O(n^2) = 2500
});
console.log(real_measure[0]*real_measure[n-1]);
