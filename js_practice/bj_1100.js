const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

let result = 0;
for(let i = 0; i < 8; i++){
    for(let j = i%2; j <= 7+i%2; j+= 2){
        if(input[i][j].localeCompare('F') == 0){
            result += 1;
        }
    }
}
console.log(result);