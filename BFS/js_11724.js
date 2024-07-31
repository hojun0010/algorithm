const input = require('fs').readFileSync(process.platform === "linux"?0:"./BFS/input.txt","utf-8").toString().trim().split('\n');


let array = input.map((e) => e.split(" ").map((x) => Number(x)));
let nm = array[0].map((e)=>Number(e));
array = array.slice(1);

let n = nm[0];  // 여기가 문제
let arr = Array.from(Array(1001),() => new Array(1001).fill(0));
let visited = Array(1001).fill(0);

for(let i = 0; i < array.length; i++){
    let x = array[i][0];
    let y = array[i][1];
    arr[x][y] = 1;
    arr[y][x] = 1;
}
let cnt = 0;
for(let i = 1; i <= n; i++){
    if(visited[i] == 0){ //일단 아직 방문하지 않은 vertex를 i를 찾자
        visited[i] = 1;

        let que = [i]; //bfs 시작
        let front = 0;
        while(front != que.length){ 
            let k = que[front];
            front++;
            for(let y = 1; y <= n; y++){
                if(arr[k][y] === 1 && visited[y] == 0){
                    visited[y] = 1;
                    que.push(y);
                }
            }
        }
        cnt++;
    }
}
console.log(cnt);

//{
//    전체 배열 탐색{
//      if(방문하지 않은 점을 발견하면){
//          dfs(i) or bfs(i); -> dfs or bfs를 실행하면 해당 vertex i에 대해 접근 가능한 모든 vertex에 대해선 한번씩은 방문한다
//          cnt++;
//      }
//    }
//}