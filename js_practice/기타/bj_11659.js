const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

let input_arr = input.map((e) => e.split(" ").map((a) => Number(a)));
let N = input_arr[0][0];
let M = input_arr[0][1];
let arr = input_arr[1];
let problem = input_arr.slice(2);
let temp = Array(N+1).fill(0);
//구간합을 저장할 배열
//구간합 d(i,j) = d(1,j) - d(1,i-1)는 만족함으로 답을 두하는데 필요한 구간합은 1부터 시작하는 경우의 모든 구간합만 있으면 된다

for(let i = 1; i <= N; i++){
    temp[i] = temp[i-1]+arr[i-1];
}
let ans = "";
for(let k = 0; k < M; k++){
    let i = problem[k][0];
    let j = problem[k][1];
    ans += temp[j] - temp[i-1] + "\n";
}
console.log(ans);