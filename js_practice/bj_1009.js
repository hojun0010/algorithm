
const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().trim().split('\n');


let arr = input.slice(0).map((el) => el.split(" ").map(Number));
const n = arr[0];
arr = arr.slice(1);

let result = [];
arr.forEach((value) => {
    let a = value[0]%10;
    let b = value[1];
    let temp = [];
    let cnt = 0;
    if(a === 0){ // a가 10의 배수 or 1의 자리가 1일때 예외처리
        result.push(10);
    }
    else if(a === 1){
        result.push(1);
    }
    else{
        while(cnt != a){ //조건이 true 일때만 돈다 ->조건이 false 이면 탈출 -> cnt가 1이거나 a이면 탈출해야한다
            //!(cnt === 1 || a === a) -> cnt !== 1 && cnt !== a
            if(cnt === 0){
                temp.push(a);
                cnt = a*a%10;
            }else{
                temp.push(cnt);
                cnt = cnt*a%10;
            }
        }
        result.push(temp.at(b%temp.length-1));
    }
   
});
result.forEach((value) => {
    console.log(value);
});

//코멘트
//a가 10의 배수일 경우 출력은 10이 되어야한다.
//temp.push(cnt) 의 위치에 따라 반복되는 수열 배열에 1로 끝날수도 있고 a로 끝날 수도 있다.
// while의 조건을 a===1일 경우를 생각해서 cnt != 1이라고 추가하면 이는 다른 숫자들의 반복 배열에서 1이 등장했을 경우에도 반복문을 중단하기 때문에
// a===1일 경우를 예외처리하고 다른 숫자들은 cnt == a일 경우에만 반복문을 탈출하도록 한다.