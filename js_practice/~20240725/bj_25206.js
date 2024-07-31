const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_sliver/input.txt","utf-8").toString().trim().split('\n');

let grade = {
    'A+' : 4.5,
    'A0' : 4.0,
    'B+' : 3.5,
    'B0' : 3.0,
    'C+' : 2.5,
    'C0' : 2.0,
    'D+' : 1.5,
    'D0' : 1.0,
    'F' : 0,
};
let arr = input.map((e) => e.split(" "));
arr = arr.map((e) => e.slice(1));
arr = arr.map((e) => Array(Number(e[0]),e[1].replace("\r",'')));

let all_sum = 0;
let grade_sum = 0;
for(let i = 0; i < 20; i++){
    if(arr[i][1] == 'P'){
        continue;
    }
    all_sum += arr[i][0] * Number(grade[arr[i][1]]);
    grade_sum += arr[i][0];
}
console.log(Number.parseFloat(all_sum/grade_sum).toFixed(6));