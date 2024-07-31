const input = require('fs').readFileSync(process.platform === "linux"?0:"./BFS/input.txt","utf-8").toString().trim().split('\n');

const firstLine = input[0].split(" ").map((e) => Number(e));
let N = firstLine[0];
let M = firstLine[1];

let array = input.slice(1).map((e) => e.split(" ").map((x) => Number(x)));
let array_temp = array;
//n,m <= 8 최대 크기는 8x8으로 64개, 바이러스(2)의 개수는 최소 2개 최대 10개, 즉 우리가 세울 벽을 선택하는 경우의 수는 
//62C3 = 62!/(3!59!) = 62*61*60/6 = 40000개 정도
//bfs 한번마다 O(n^2) => 64 * 40000 = 총 256만개? - 행렬사용시
let visited = Array.from(Array(N),()=> new Array(M).fill(false));







function setBlock(block_cnt){
    for(let i = 0; i < N; i++){
        for(let j = 0; j < M; j++){
            if(array_temp[i][j] == 0){
                array_temp[i][j] = 1;
                block_cnt++;
                setBlock(block_cnt);
                if(block_cnt == 3){
                    return 0;
                }
            }
        }
    }
    
}


let dx = [-1,1,0,0];
let dy = [0,0,-1,1];

function bfs(x,y){   //3개의 block을 세운뒤에 바이러스로부터 bfs를 진행, 탐색도중 마주치는 0을 모두 1로 바꾸었을때
    //남은 1의 개수가 가장 큰 경우를 찾아야한다.
    let que = [[x,y]];
    let front = 0;
    if(!visited[x][y]){
        let k = que[front];
        front++;    
        while(que.length != front){
            for(let i = 0; i < 4; i++){
                for(let j = 0; j < 4; j++){
                    let nx_x = k[0]+dx[i];
                    let nx_y = k[1]+dy[j];
                    if(nx_x < 0 || nx_x >= N) continue;
                    if(nx_y < 0 || nx_y >= M) continue;
                    if(!visited[nx_x][nx_y] && array_temp[nx_x][nx_y] == 0){
                        que.push([nx_x][nx_y]);
                        visited[nx_x][nx_y] = true;
                    }
                }
            }
            visited[x][y] = true;
            que.push([x,y]);
        }
    }
}


