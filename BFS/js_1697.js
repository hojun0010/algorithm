const input = require('fs').readFileSync(process.platform === "linux"?0:"./BFS/input.txt","utf-8").toString().trim().split('\n');

let n = Number(input[0].split(" ")[0]);
let k = Number(input[0].split(" ")[1]);
let que = [n]; //queue에 들어간 노드의 개수는 계산과정 중에 나오는 결과값 x의 경우의 수, 
let visited = Array(100001).fill(0);

let r = -1;
let front = 0; //array를 queue 형식으로 사용하기 위해 queue.pop이 작동하는 방식으로 array에서 front가 위치하는 인덱스 값
let back = 1; //array를 queue 형식으로 사용하기 위해 데이터가 삽입되는 인덱스 위치
while(r != k){
    while(que.length >= 1 && r != k){
        r = que[front];
        if(r == k){
            break;
        }
        front++;
        let cal = [r-1,r+1,r*2];
        for(let i = 0; i < cal.length; i++){
            if(cal[i] == k){
                visited[cal[i]] = visited[r]+1;
                r = cal[i];
                break;
            }
            if(visited[cal[i]] == 0 && cal[i] <= 100000){
                que.push(cal[i]);
                visited[cal[i]] = visited[r]+1;
            }
        }
    }
}
console.log(visited[k]);
//5
//4 6 10
//[3 5 8] [5 7 12] [9 11 20]
//[[2 4 6],[7 9 16],[7 9 16]],[[]]
//메모리 초과 -> 시간초과로 틀림 -> 틀림(문제가 뭘까?) -> n = k 일때 출력이 되지 않는다. why?
//시간 초과 문제 -> 얼마까지 visited를 유지해야하는가? -> 
// x > 50000보다 클경우 x에 -1을 계속 더해 50000까지 만든 후 *2 하면 답이 된다. 
// 