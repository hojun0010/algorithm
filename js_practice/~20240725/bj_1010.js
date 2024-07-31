const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice(b2-s3)/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

// 다리는 서로 겹쳐질 수 없다. (n <= m) 이므로 n의 사이트는 모두 사용되어야 하며 m의 사이트는 모두 사용되거나 남을 수 있다.
// res(n,m) = 사이트의 개수가 n,m이라고 할때 전체의 경우의 수라고 정의하면
// 1) res(n,m) = 1(n == m) 일때
// 2) res(n,m=n+1) => m에서 하나의 사이트만 남는 경우의 수 = n+1 = (n+1)res(n,n)
// 3.1) res(n,m) (m = n+k) = res(n,n+k)라 하면 k개를 n+k개에서 선택하는 경우의 수 = n+kCn = (n+k)!/(n! * k!)
// (n+k)! = m! m< 30 이므로 계산 범위를 초과할 듯 하다
// 3.2) res(n,m) = res(n,m-1)를 m번 반복 -> 목적지의 m-1개를 m개 중에서 선택하는 경의 수이므로 m-1개의 조합은 m개가 등장하고 각 m-1개의 조합당
// res(n,m-1)개의 경우의 수가 존재한다 즉 => res(n,m) = m * res(n,m-1) -> 반례를 발견 res(1,30)의 경우 답은 30이지만 구한 공식으론 30 * 29 .... 가 된다
// 2) 에서 발전 3.3) res(n,n+2) = res(n,n+1) + res(n,n+1) 인가? -> n개의 점에 대해 위아래로 1개씩 점이 추가되었다고 생각하면,
// 위의 점만을 경우의 수에 포함하는 경우와 아래의 점만을 경우의 수에 포함하는 경우로 나누어 생각 -> 반례 이는 추가된 위아래 점 모두를 포함하는 경우를 생각할 수 없다.
// 3.4) res(n,n+2) = (n+2) * res(n,n+1), n+2개의 점들중 res(n,n+1)에 포함될 n+1개의 점을 뽑는 경우의 수 = 포함되지 않을 점 한개를 고르는 경우의 수 : n+2개 
// 오류를 발견 -> n+2개 중에서 n+1개를 고르는 과정에는 정해진 n개의 숫자 집합이 겹쳐질 수 있다.
// res(2,4)에 대해 res(2,2)에서 선택된 것을 [1,2]라고 하면 [1,2,3,4]로 추가된 경우 3개의 조합을 찾는 과정 (1,2,3)(1,2,4)에서 (1,2)가 겹치게 되고
// 각각의 (1,2,3)과 (1,2,4)는 이 세 숫자 중 2개를 골라 좌측과 연결한다는 의미이므로 (1,2)가 선택되는 경우가 중복된다.
// 3.5) res(n,n+2)를 res(n,n)으로 정의하는 방법? : n+2개 중 n개를 선택 n+2Cn = (n+2)! / n! 2! = (n+2)(n+1)/2
// 4) res(n,n+k) => n+k중 n개를 선택하는 방법 n+kCn = (n+k)(n+k-1)... (n+1) / k!
// 5) 범위 고려 : 0 < n <= n+k < 30, 0 <= k < 30-n...=> 29 범위를 벗어날것 같은데?

// BigInt로 풀긴했지만 팩토리얼은 범위를 너무 벗어나기 때문에 다른 방법으로 푸는것이 나을것 같다. => 파스칼 삼각형
// https://blog.naver.com/mondvopel/220020337593
// 피라미드 모양의 숫자 배열을 1씩 증가시키면서 규칙따라 늘어나는 삼각형 / 1 / 1 1 / 1 2 1 / 1 3 3 1 / 1 4 6 4 1 ...
// 이항 계수의 정리 : nC(k-1) +nCk = (n+1)Ck 가 성립한다. 이를 바탕으로 파스칼 삼각형을 조합의 표현으로 바꿀 수 있으며 각 조합은 자신 위치의 위의 2개의 조합의 합에 해당한다.
// 이를 바탕으로 n+kCn = (n+k-1)C(n-1) + (n+k-1)Cn .... 으로 표현 가능하며 하위식들을 또 그 식들의 하위식으로 재귀적 혹은 반복적으로 구하면서 숫자의 범위를 벗어나는것 없이 문제를 해결 할 수 있다.


let t = Number(input[0]);
let result = [];
let arr = input.slice(1).map((e) => e.split(" ").map((k) => Number(k)));
// console.log(arr);
for(let i = 0; i < t; i++){
    n = arr[i][0];
    m = arr[i][1];
    result.push(res(n,m));
}
result.forEach(element => {
    console.log(element);
});

function res(n,m){
    let result = 1n;
    if(n == m) return 1;
    if(n == 1) return m;
    let k = m-n;
    while(m != n){
        result *= BigInt(m);
        // console.log("m : " + m + " result  : " +result);
        m--;
    }
    while(k > 1){
        result /= BigInt(k);
        k--;
    }
    return Number(result);
    
}