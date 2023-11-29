#include <iostream>
#include <stack>

using namespace std;

//해결 개념 : stack을 사용한다. )가 입력될경우 가장 최근에 입력된 ( 와 짝을 짓는다.
//답이 틀릴 경우는 총 2가지로 (이 많은 경우와 )가 많은 경우 -> (가 많은경우 )와 짝을 짓기 위해 유지시켯던 (가 () 입력을 모두 탐색한 결과 남아있게 된다.
//) 가 많은 경우는 )가 입력되었을때 짝을 짓기 위해 유지시켯던 (가 현재 존재하지 않는 상황
//( 를 스택으로 유지시키고 )가 입력되면 짝을지어 가장 최근의 (를 pop한다. 
//예외의 경우 2가지는 1. (가 많은경우 : 모든 입력을 탐색한수 스택에 값이 남아있으면 false
//2. )가 많은 경우 : 입력을 탐색하는 동안 )와 짝지을 최근에 탐색할 (가 존재하지 않음 false

//고칠점 : 이 문제의 경우 입력 문자열을 동적으로 선언할 필요가 없다. 
//https://www.acmicpc.net/source/4610349
//답안 코드 : 굳이 문자열을 탐색하면서 유지시킬필요가 없다. 
//for (int j = 0; s[j] && c >= 0; j++) s[j] == '(' ? c++ : c--; 
//j로 입력문자열을 탐색하면서 값이 존재하는동안 또한 c('('의 개수)가 0보다 같거나 클다면 계속 탐색한다. 답인 경우는 무조건 c가 0이 된다.
//'('가 많은 경우는 for문 탐색 완료후 c가 0보다 크다면 답이 아니라고 간주
// ')'가 많은 경우는 문자열을 전체 탐색하기 전에 c가 0보다 작아지고 for문을 벗어난다.
// 답인 경우는 무조건 0이므로 0이 아니라면 NO 0이라면 Yes를 출력한다.

int n;
stack<int> st;
bool ans = true;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        char* c = new char[51];
        cin >> c;
        if(c[0] == ')'){
                cout << "NO" << "\n";
                continue;
        }
        st.push(1);
        for(int j = 1; j < 51; j++){
            if(c[j] == '(') st.push(1);
            else if(c[j] == ')'){
                if(st.empty()){
                    ans = false;
                    break;
                }else{
                    st.pop();
                }       
            }
            else{
                break;
            }
        }
        if(!st.empty()) ans = false;

        if(ans){
            cout << "YES";
        }else{
            cout << "NO";
        }
        if(i != n-1) cout << "\n";
        ans = true;
        while(!st.empty()){
            st.pop();
        }
    }
}