const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

let n = Number(input[0]);
let f = Number(input[1]);
let result = 0;

if((n-n%100)%f === 0){
    result = 0;
}
else{
    result = f - ((n-n%100)%f);
}

if(Math.floor(result/10) === 0){
    console.log('0'+result.toString());
}
else{
    console.log(result.toString());
}

//n = k * 몫 + 나머지 (k < 100)
//구하고자 하는것은 1의 자리와 10의 자리 숫가의 최소값, 즉 나머지를 0으로 하는 n의 최소값을 구한다. 
//n의 최소값은 구하는 2자리 숫자가 모두 00인 수이며 (n의 가능한 최소값) = k * 몫 + 나머지 의 식에서 나머지가 존재한다면 
//(n의 가능한 최소값) = k * (몫+1) + 나머지 - k -> (n의 가능한 최소값) + k - 나머지 = k * (몫 + 1)가 성립한다 (k-나머지 > 0)
// 예외 고려 1) n이 00으로 끝나는 경우 = 이경우에도 식이 성립
// 2) 테스트 케이스 실행중 f와 동일한 값이 등장, 23442 75 -> 23400 = 75 * 312 + 0  -> 23400 + k - 0 = 75 * (312 + 1) 
// 즉 위의 식은 나머지가 0일때는 성립하지 않는다.