let input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());
console.log(input);
let cnts = [];
for(let i = 0; i < input.length-2; i++){
    let str = input[i].toLowerCase();
    // console.log(str);
    let cnt = 0;
    for(let j = 0; j < str.length; j++){
        let char = str[j];
        if(char === 'o' || char === 'a' || char === 'e' || char === 'i' || char === 'u') cnt++;
    }
    cnts.push(cnt);
}
cnts.forEach(element => {
    console.log(element);
});