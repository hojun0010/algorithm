let input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split(' ').map((e) => e.trim());

let nums = input.map((e)=>Number(e));
//주어진 5개의 숫자중 최소한 3개의 수를 약수로 가지는 수의 최소값
//5개 중 3개를 중복없이 선택하는 경우의 수 = 5c3 => 60개
//1)3개를 고르는 것보다 4개를 골랐을때 공배수가 가장 작아지는 경우가 존재하나? -> 추가로 고른 1개가 1인 경우 + 고른 3개의 수의 약수 일때 동일하며
//그 외엔 공배수가 커진다 -> 3개만 골라도 답엔 이상이 없다.

//3개의 숫자가 주어질때 이 수를 모두 약수로 가지는 최소공배수는 얼마인가
//99까지의 모든 수를 인수분해 해놓고 주어진 3개의 수에 대해 모든 인수를 곱하되 필요없는 중복을 제거해 3개 수에 대해 배수를 구한다. 
//ex) 30 42 70 => [2 3 5],[2 3 7],[2 5 7] => [2 2 2 3 3 5 5 7 7] => [2 3 5 7]

let result = 10000000;
let cds = [0,[1],[2]]; //cds[i] = i를 인수분해하는 식 cds[30] = [2,3,5] = [3] + cds[10]
for(let i = 3; i <= 100; i++){
    cds.push(getCd(i));
}
//console.log(cds);
for(let i = 0; i < 3; i++){
    let num1 = cds[nums[i]];
    for(let j = i+1; j < 4; j++){
        let num2 = cds[nums[j]];
        for(let q = j+1; q < 5; q++){
            let num3 = cds[nums[q]];
            // console.log("num1 : " + num1 + " num2 : " + num2 + " num3 : " + num3);
            // let nums12 = num1.concat(num2.filter((x) => !num1.includes(x))); 
            // let arr = nums12.concat(num3.filter((x) => !nums12.includes(x)));
            let nums12 = makeDifference(num1,num2);
            let arr = makeDifference(nums12,num3);
            // console.log("arr : " + arr);
            let cm = arr.reduce((a,b) => a*b);
            if(cm < result) result = cm;
        }
    }
}
//생각한 해결방법 중 잘못된점 
//1)set을 사용하니 1,2,4 등 result가 같은 인수의 반복으로 이루어질 경우를 포함하지 않는다.
//ex) 9,18,54 => 3 3 / 2 3 3/ 2 3 3 3 
//num1이 num2에 속한다면 result = num2, 속하지 않는다면 속한부분을 빼고 result에 추가 즉 num1,num2,num3의 합집합을 구하면 그 집합이 세 수의 최소 공배수이다.

// array1.concat(array2) 두 배열을 합한 새로운 배열을 반환한다.
//num2.filter(x => !num1.includes(x)), filter(callbackFn) 내부의 콜백함수는 배열의 요소를 인자로 받아 true를 반환하는 요소만을 필터링된 배열에 적용한다.
//!num1.includes(x), includes는 num1에 x라는 값이 포함될 경우 true를 반환, 아니면 false를 반환한다. 차집합을 만들기 위해 !, 부정을 취한다.
//따라서 num2.filter(x=> !num1.include(x))는 num2 배열에서 num1에 속하는 요소를 제외하고 반환, 즉 num2의 num1과의 차집합을 반환
//num1의 전체 + num2의 차집합이 num1과 num2의 합집합이 된다.

//2) 합집합을 사용 -> include() 함수 특성상 중복이 제거된다 
//-> num2에 속하는 x가 num3에 있는지 탐색하는 과정 중 num3에 x가 2개 존재한다면 공배수 특성상
//x 한개를 결과값에 반영해야하지만 x 2개 모두 지워져 결과갑엔 num2에 속하는 x 하나만 반영된다.
//ex) 2,4의 경우 [2] [2 2]로 구성, num2.filter((x) => num1.includes(x))의 결과로  [2 2]를 반환해야하지만 [2]가 반환된다.
//해결책 -> include()말고 합집합을 만들되 중복을 허용하는 방법이 있나? + 방법을 구현하는 도중 약수와 인수분해를 번갈아 가면서 사용해 문제가 발생
// 인수분해만을 이용하는것으로 수정한다.
//
console.log(result);

function getCd(i){
    for(let j = 2; j <= Math.sqrt(i); j++){
        if(i % j === 0){
            let arr = [j];
            return [...arr , ...getCd(Math.floor(i/j))];
            //함수 구성의 문제
            //합집합으로 답을 구할 경우 각 i에 대해 배열 nums에 저장할 값은 약수가 아니라 인수분해한 값이 된다.
        }
    }
    // return [1,i]; //이 경우는 약수인 경우
    return [i]; //소수인 경우이며 소수는 인수분해 할 시 자기자신과 1의 곱으로 표현된다.
}
function makeDifference(num1, num2){

    let result = [];
    let nums1 = num1.slice();
    let nums2 = num2.slice(); //
    nums1.forEach(element => {
        let num2length = num2.length;
        for(let i = 0; i < num2length; i++){
            if(element == nums2[i]){
                // nums2.splice(i,1); 인자로 받은 num2가 복사된 nums2에 행해진 삭제 연산이 실제 num2가 저장되있는 cds 배열에 적용되는 것을 확인
                // nums1, nums2를 인자로 받은 num1,num2에 slice()를 적용, 얕은 복사가 아닌 새로운 배열 객체본이 반환되도록 설정
                nums2.splice(i,1);
                // console.log("nums2 : " +nums2);
                break;
            }
        }
    });
    if(nums2.length !== 0){
        result = nums1.concat(nums2);
    }
    else{
        result = nums1;
    }
    return result
}

//다른 풀이 방법
//1) https://www.acmicpc.net/source/701859 처음에 시도 했던 gcd 공식을 이용, lcm(x,y) = (x*y)/gcd(x,y)을 이용해 lcm을 구한다 <- 논리가 이해가 안된다.
//2) 배수를 구한다는 마인드가 아니라 그냥 1부터 시작해서 1씩 더해가면서 5개중 3개의 배수이면 그 값을 출력한다. -> 보통 이 방법대로 풀은듯하다.
//3) 