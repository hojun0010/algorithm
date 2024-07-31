const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice(b2-s3)/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

//행성계의 진입과 이탈 횟수 중 가장 최소를 구하라
//가정 : 시작점 i이 속한 행성계의 수를 a라 하고  도착점 j이 속한 행성계의 수를 b라 하면 답은 a+b 이다
//예외 : 위의 경우는 i,j가 동시에 속하는 행성계가 존재하지 않을때에 한정한다 -> 동시에 속하는 행성계가 존재할 경우
//동시에 속하는 생성계를 리스트에서 삭제 후 a,b를 다시 구하면 답이 나온다.
let t = Number(input[0]);
let result = [];
let arr = input.slice(1); //1부터 마지막까지 배열값을 반환
// console.log(arr);
for(let i = 0; i < t; i++){
    let res = 0;
    let xy = arr[0].split(" ").map((e)=>Number(e));
    // console.log("xy : " + xy);
    arr.splice(0,1);
    let start = xy.slice(0,2);
    let end = xy.slice(2,4);
    let n = Number(arr[0]);
    // console.log("start : " + start + " end : " + end);
    arr.splice(0,1);
    // console.log(arr);
    for(let j = 0; j < n; j++){
        let circle = arr[j].split(" ").map((e)=>Number(e));
        // console.log("circle" + j + " : " + circle);
        if(isInCircle(start,circle) == true && isInCircle(end,circle) == false){
            res++;
        }
        else if(isInCircle(start,circle) == false && isInCircle(end,circle) == true){
            res++;
        }
    }
    arr.splice(0,n);
    result.push(res);
}
result.forEach(element => {
    console.log(element);
});


function isInCircle(dot, circle){
    let r = circle[2];
    // x2 + y2 <= (c1-r)2 + (c2-r)2 면 dot 좌표는 circle 안에 존재한다.
    if(Math.pow(dot[0]-circle[0],2)+Math.pow(dot[1]-circle[1],2) <= Math.pow(r,2)){
        return true;
    }else{
        return false;
    } 
}