const input = require('fs').readFileSync(process.platform === "linux"?0:"./BFS/input.txt","utf-8").toString().trim().split('\n');
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

// console.log(arr);
let visited = Array.from(Array(n) ,() => new Array(m).fill(0)); //from -> iterable을 이용하여 nxm 크기의 0으로 초기화된 2차원 배열을 만든다
visited[0][0] = 1;
let que = [[0,0]];

let upleft = [[1,0],[0,1]];
let upright = [[1,0],[0,-1]];
let downleft = [[0,1],[-1,0]];
let left = [[1,0],[0,1],[-1,0]];
let right = [[1,0],[0,-1],[-1,0]];
let up = [[1,0],[0,1],[0,-1]];
let down = [[0,1],[0,-1],[-1,0]];
let common = [[0,1],[1,0],[-1,0],[0,-1]];
function findCalculation(a,b){
    if(a == 0){
        if(b == 0) return upleft;
        else if(b == m-1) return upright;
        else return up;
    }
    else if(a == n-1){
        if(b == 0) return downleft;
        else return down;
    }
    else{
        if(b == 0) return left;
        else if(b == m-1) return right;
        else return common;
    }
}

let x = 0;
let y = 0;
while(x != n-1 || y != m-1){
    let xy = que[0];  //선입선출인 queue를 이용하기 위해 array의 인덱스 0인 값을 갖고온 후
    que = que.slice(1); //그 0인 값을 삭제한다.
    x = xy[0];
    y = xy[1];
    // console.log("que pop => "+x+" "+y);
    // console.log("que => "+que);
    let cal = findCalculation(x,y);
    for(let i = 0; i < cal.length; i++){
        let nx_x = x+cal[i][0];
        let nx_y = y+cal[i][1];
        if(arr[nx_x][nx_y] !== 0 && visited[nx_x][nx_y] == 0){
            que.push([nx_x,nx_y]);
            visited[nx_x][nx_y] = visited[x][y]+1;
        }
    }
}
console.log(visited[n-1][m-1]);

// 1. 재귀함수를 통하여 shortest path를 구하기 -> Maximum call stack size exceeded 오류가 발생 -> 재귀함수가 실행 대기중인 콜 스택에 쌓임에 따라 그 한계를 벗어나면 발생하는 오류
// 2. 재귀함수 말고 다른 방법이 있는가 -> bfs가 쉽다고 한다... 왤케 모르겟냐