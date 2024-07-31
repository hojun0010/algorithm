const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice(b2-s3)/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

let n = Number(input[0]);
let cntArr = [...new Array(1001)].map((e) => 0);
let aArr = input[1].split(" ").map((e)=>Number(e));
let bArr = [...new Array(aArr.length)].map((e) => 0);
let ans = Array(n).fill(-1);
//i = 0,1,2,3...
//p = 순서가 상관없이 0부터 n-1까지의 수를 포함하는 배열
//a에 p를 적용한 결과, 즉 b가 비내림차순이 되는 p를 구하여라
//비내림차순의 조건 => 바로 앞의 원소보다 크거나 같기만 하면 된다 -> 무조건 정렬이여야만 하나? p[i]는 중복 될수 없고, A[i]도 마찬가지
//1 2 3이면 가능, 2 3 1 이면 가능하지 않는다.
//b[0] = b[p[i]] 에서 p[i1] = 0일때 b[0] = a[i1]이며 b[0] = 최소값이다.
// -> 결국 A의 원소를 정렬했을때 각 원소의 인덱스 값 => p의 배열값이 된다.

for(let i = 0; i < aArr.length; i++){
    let cnt = 0;
    for(let j = 0; j < aArr.length; j++){
        if(i == j) continue;
        if(aArr[i] > aArr[j]) cnt++;
    }
    ans[i] = cnt+cntArr[aArr[i]];
    // console.log(cnt+cntArr[aArr[i]]+" push");
    cntArr[aArr[i]]++;
}
let answer = "";
for(let i = 0; i < aArr.length; i++){
    bArr[ans[i]] = aArr[i];
}
// console.log(bArr);
console.log(ans.join(" "));
