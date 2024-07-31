let input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());
let cnt = 0;
// console.log("Intinput = " +input);
while(cnt != 3){
    cnt++;
    let n = Number(input[0]);
    let arr = input.slice(1,n+1).map((e)=>BigInt(e));
    // console.log("arr : "+arr);
    input.splice(0,n+1);
    // console.log("input : " + input);
    //input에 대한 arr1이 위치하는 index 값
    //n1 [a1 ... a(n1-1) -> 총 n1개] n2 [0   ...   n2-1] n3        [0      ...  n3-1] = 배열값
    // 0  1 ...           n1       n1+1 [n1+2...n2+n1+1] n2+n1+2   [n2+n1+3...  n2+n1+n3+2] =인덱스값
    let sum = 0n;
    for(let i = 0; i < n; i++){
        sum+= arr[i];
    }
    if(sum === 0n) console.log(0);
    else{
        sum>0n ? console.log("+"):console.log("-");;
    }
}

