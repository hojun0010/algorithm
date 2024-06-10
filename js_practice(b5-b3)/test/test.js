let input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/test.txt","utf-8").toString().split(' ');
console.log(typeof(input));
console.log(input);


let input2 = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/test2.txt","utf-8").toString().trim().split('\n');
let arr = input2.slice(1).map((el) => el.split(" ").map(Number));
//Array.map(k) => 배열의 모든 요소에 k 함수를 호출한 결과를 모아 새로운 배열을 반환한다.
//el = input2.slice(1)의 모든 배열의 요소에 해당, 그 요소 즉 '4 6\r'이 하나의 el이 되고 이 el에 .split(" ").map(Number)를 진행 결과
//split(" ")로 ['4', '6\r']이 반환, map(Number)으로 [4,6]이라는 배열이 반환된다. 
console.log(input2)
console.log(arr);



//https://minjo0n.tistory.com/2
//백준  : 자바스크립트 입력 받아오는 방법
//https://velog.io/@ichenny/%EB%B0%B1%EC%A4%80-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-11651%EB%B2%88%EC%A2%8C%ED%91%9C%EC%A0%95%EB%A0%AC%ED%95%98%EA%B8%B0-2-JS-2%EC%B0%A8%EC%9B%90-%EB%B0%B0%EC%97%B4-%EC%A0%95%EB%A0%AC%ED%95%98%EA%B8%B0
