const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_sliver/input.txt","utf-8").toString().trim().split('\n');

let n = Number(input[0]);
let arr = input.slice(1);
arr.sort(function(a,b){
    return a-b;
});

let ans = '';
for(let i = 0; i < n; i++){
    // console.log(arr[i]);
    ans += arr[i]+ "\n";
}
console.log(ans);

//n = 1 000 000 n or nlogn or logn 정도
//자바스크립트는 Array.sort()를 진행할때 해당 요소를 모두 문자열로 변환해서 수행한다. -> 숫자 100, 5, 6, 7 배열의 경우 100,5,6,7로 정렬된다. 
//시간 초과 -> console.log()의 호출 횟수가 증가함에 따라 걸리는 시간은 더 많이 걸린다 -> 답을 하나의 문자열에 저장해서 한번만 출력한다.