const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_sliver/input.txt","utf-8").toString().trim().split('\n');

let n = Number(input[0]);
let arr = input.slice(1);
arr = arr.map((e) => e.replace('\r',""));
// console.log(arr);

arr.sort(function(a,b){
    for(let i = 0;i<50 ;i++){
        if(a.length != b.length){
            return a.length - b.length;
        }
        if(a.charAt(i).codePointAt() == b.charAt(i).codePointAt()) continue;
        else{
            return a[i].codePointAt() - b[i].codePointAt();
        }
    }
})

let ans = "";
let temp = "";
for(let i = 0; i < n; i++){
    if(temp == arr[i]) continue;
    ans += arr[i] +"\n";
    temp = arr[i]
}
console.log(ans);
