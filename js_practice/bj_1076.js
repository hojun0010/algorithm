const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());
console.log(input);

let arr = ["black","brown","red","orange","yellow","green","blue","violet","grey","white"];
console.log((10*arr.indexOf(input[0])+arr.indexOf(input[1]))*Math.pow(10,arr.indexOf(input[2])));