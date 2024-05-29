let input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

let n = Number(input[0]);
let arr = input[1].split(' ').map((e)=>Number(e));
let num1 = 0;
let num2 = 0;
arr.forEach(element => {
    num1 += 10*(Math.floor(element/30)+1); 
}); 
arr.forEach(element => {
    num2 += 15*(Math.floor(element/60+1)); 
});

if(num1 === num2) console.log("Y M "+num1);
else{
    num1 > num2 ? console.log("M "+num2) : console.log("Y "+num1);
}
//0~29 30~59 60~99 ...
//몫0 몫1 몫2 -> 그냥 몫에 +1 하면 될듯