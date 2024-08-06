const input = requir1e('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

let input_arr = input.map((e) => e.split(" ").map((a) => Number(a)));
let N = input_arr[0][0]; // 전체 나무의 개수 ~백만
let M = input_arr[0][1]; // 필요한 나무 길이 ~20억
let arr = input_arr.slice(1); // 나무 정보 배열 각 나무는 10억보다 작다
//최대 큰 나무 길이부터 시작해서 필요한 나무길이가 나오도록 톱 길이를 설정하는 경우의 수는 
//나무의 최대 길이(10억) * 톱 길이를 설정할때마다 나무 배열을 모두 탐색(100만) => 시간 초과날듯...
//이분 탐색 & 매개 변수 탐색 문제... -> 뭔지 모름...
let tree_max = 


