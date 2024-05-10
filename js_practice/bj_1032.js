const input = require('fs').readFileSync(process.platform === "linux"?0:"./js_practice/input.txt","utf-8").toString().split('\n').map((e) => e.trim());

const n = Number(input[0]);
let text = input.slice(1);
let main_text = text[0];
let result = new String();

for(let i = 0; i < main_text.length; i++){
    let everyCharSameIs = true;
    let main_char = main_text[i];
    for (let j = 1; j < n; j++){
        let compare_char = text[j][i];
        if(main_char.localeCompare(compare_char) !== 0){
            everyCharSameIs = false;
            break;
        }
    }
    if(everyCharSameIs){
        result += String(main_char);
    }
    else{
        result += String("?");
    }
}
console.log(result);