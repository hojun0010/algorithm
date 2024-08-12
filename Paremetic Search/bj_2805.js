const input = require("fs")
  .readFileSync(
    process.platform === "linux" ? 0 : "./Paremetic Search/input.txt",
    "utf-8"
  )
  .toString()
  .split("\n")
  .map((e) => e.trim());

let input_arr = input.map((e) => e.split(" ").map((a) => Number(a)));

let N = input_arr[0][0]; // 전체 나무의 개수 ~백만
let M = input_arr[0][1]; // 필요한 나무 길이 ~20억
let arr = input_arr[1]; // 나무 정보 배열 각 나무는 10억보다 작다
//최대 큰 나무 길이부터 시작해서 필요한 나무길이가 나오도록 톱 길이를 설정하는 경우의 수는
//나무의 최대 길이(10억) * 톱 길이를 설정할때마다 나무 배열을 모두 탐색(100만) => 시간 초과날듯...
//이분 탐색 & 매개 변수 탐색 문제... -> 뭔지 모름...

let start = 0; // 톱길이를 1으로 하면 가장 긴 나무 조각의 길이 합을 가진다.
let end = Math.max(...arr); //arr에 저장된 최대 나무 길이에 -1?
while (start < end) {
  let mid = Math.floor((start + end) / 2);
  let tree = 0;
  for (let i = 0; i < arr.length; i++) {
    tree += arr[i] - mid > 0 ? arr[i] - mid : 0; //해당 mid 값을 톱 길이로 할때 반환되는 총 tree의 길이
  }
  if (tree == M) {
    end = mid;
    break;
  }
  if (tree < M || start == mid) {
    //tree가 M보다 작으면 end쪽에 가까운 경우
    //나눗셈의 특성상 start + end가 홀수라면 start == mid가 true 경우가 발생하며 이때 무한루프가 발생할 수 있다.
    //start + end가 짝수라면 위의 if문에서 이미 break 되기 때문에 이 경우만 예외처리하면 된다.
    // start == mid인 상황에서 end를 mid값으로 재설정하면 start = mid = end이므로 while문을 탈출하고 답을 출력한다.
    end = mid;
  } else if (tree >= M) {
    //tree가 M보다 크면 1쪽에 가까운 경우
    start = mid;
  }
}
console.log(end);
