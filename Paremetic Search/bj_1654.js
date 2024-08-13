const input = require("fs")
  .readFileSync(
    process.platform === "linux" ? 0 : "./Paremetic Search/input.txt",
    "utf-8"
  )
  .toString()
  .split("\n")
  .map((e) => e.trim());

let kn = input[0].split(" ").map((e) => Number(e));
let k = kn[0];
let n = kn[1];
let arr = input.slice(1).map((e) => Number(e));

//k개의 랜선을 가지고 있는데 n개의 랜선을 가지고 싶다, 이 n개의 랜선은 모두 같은 길이로 이루어져 있으며 n은 고정이 된다.
//즉 n개의 랜선의 길이를 매개 변수로 잡고 이 매개변수를 넣었을때 반환되는 값은 랜선의 갯수, -> 이 값이 n이 될때를 구하여라? -> n개 이상 만들때도 포함이였다
//그럼 잘랐을때의 결과인 n개의 랜선의 길이를 매개변수로 잡고, 이 매개변수를 넣었을때 반환되는 함수값은 만들어 지는 랜선의 개수
//조건은 n>= 11 이며 start = 1부터 end = 소유한 랜선의 길이중 가장 큰 값, 즉 함수 결과 배열은 [모든랜선의합, ... , 1] 으로 시작되며
//조건에 따라 [t t t t t t ... t f f f ... f]로 진행될 것이며 우리는 f가 되기 직전의 true일때를 찾아야한다.

let start = 0;
let end = Math.max(...arr) + 1; // start, end값은 실제 값이 될수 있는 범위를 벗어나게 하자,
while (start < end) {
  let mid = Math.floor((start + end) / 2);
  let mid_n = 0;
  for (let i = 0; i < arr.length; i++) {
    mid_n += Math.floor(arr[i] / mid);
  }
  // 나눗셈 특성상 합이 홀이면 start = mid인 경우가 생기고 이 경우 무한루프가 발생한다.
  if (mid_n < n || start == mid) {
    end = mid;
  } else if (mid_n >= n) {
    start = mid;
  }
}
console.log(end);
