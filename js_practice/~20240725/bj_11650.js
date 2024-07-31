const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_sliver/input.txt","utf-8").toString().trim().split('\n');

let n = Number(input[0]);
let arr = input.slice(1);
arr = arr.map((e)=>e.split(" "));
arr = arr.map((ar) => ar.map((a) => Number(a)));
// console.log(arr);

arr.sort(function(a,b){
    if(a[0] == b[0]){
        return a[1]-b[1];
    }
    else{
        return a[0]-b[0];
    }
})
let ans = "";
for(let i = 0; i < arr.length; i++){
    ans += arr[i][0] + " " + arr[i][1] + "\n";
}
console.log(ans);