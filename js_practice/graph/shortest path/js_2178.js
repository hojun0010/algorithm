const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/graph/shortest path/input.txt","utf-8").toString().trim().split('\n');
let n = Number(input[0].split(" ")[0]);
let m = Number(input[0].split(" ")[1]);
let arr = input.slice(1);
arr = arr.map((e)=> e.replace("\r",""));
arr = arr.map((e) => e.split(""));
arr = arr.map((e) => e.map((a) => Number(a)));
//지나갔던 칸들을 기억하면서 칸을 이동할때마다 그 칸과 인접하면서 이전까지 방문하지 않았던 칸을 탐색한다. 이때 방문할수 있는 칸이 없으면
//바로 직전에 방문한 칸으로 다시 돌아가서 방문할수 있는 칸이 없던 칸은 제외하고 다른 방문할 수 있는 칸이 있는지 탐색해야한다.
//지나갔던 칸, 즉 현재의 탐색 루트는 스택으로 유지하며 우선적으로 (i,m) 좌표에서 i,m이 각각 증가하는 칸을 탐색한다.
//(감소하는 좌표로의 루트는 그러한 루트만이 존재하는 경우가 아니라면 무조건 증가하는 좌표들로 구성된 루트가 최소한의 루트이다.)

//자바스크립트에서 stack은 stack 자료구조를 구현할 필요 없이 Array에 내장된 함수인 push()와 pop()을 이용하여 stack의 특성을 이용할 수 있다.


let visited = Array.from(Array(n),() => new Array(m).fill(0));
let up_bound = [[1,0],[0,1][0,-1]]; //윗변에서 모서리부분을 제외한
let right_bound = [[1,0],[0,-1],[-1,0]]; //오른변에서 모서리부분을 제외한
let bottom_bound = [[0,1],[0,-1],[-1,0]];//아래변에서 모서리부분을 제외한
let left_bound = [[0,1],[0,-1],[-1,0]];
let upleft = [[1,0],[0,1]]; //(0,0)
let upright = [[1,0],[0,-1]]; //(0,m)
let downleft = [[0,1],[-1,0]]; //(n,0)
let common = [[0,1],[1,0],[0,-1],[-1,0]]; //4개의 칸이 접하는 일반적인 구간
find(0,0);


function find(x,y){

    while(true){
        visited.push(stack.pop());
        let list = visited.pop();
        let a = list[0];
        let b = list[1];
        console.log(a,b);
        if(a == n && b == m){
            console.log(visited.length);
            break;
        }
        let searchArr = SetSearchArray(a,b);
        for(let i = 0; i < searchArr.length; i++){
            let nx_a = a + searchArr[i][0];
            let nx_b = b + searchArr[i][1];
            if(arr[nx_a][nx_b] == 1 && visited.findIndex((e) => e == [nx_a,nx_b]) == -1) stack.push([nx_a,nx_b]);
        }
    }
   
}
function SetSearchArray(a,b){
    if(a == 0){
        if(b == 0) return upleft;
        else if(b == m) return upright;
        else up_bound;
    }
    else if(a == n){
        if(b == 0) return downleft;
        else return bottom_bound;
    }
    else if(b == 0) return left_bound;
    else if(b == m) return right_bound;
    else return common;
}
// 1. 재귀함수를 통하여 shortest path를 구하기 -> Maximum call stack size exceeded 오류가 발생 -> 재귀함수가 실행 대기중인 콜 스택에 쌓임에 따라 그 한계를 벗어나면 발생하는 오류
// 2. 재귀함수 말고 다른 방법이 있는가 -> bfs가 쉽다고 한다... 왤케 모르겟냐