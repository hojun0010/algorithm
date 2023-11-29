#include <iostream>
#include <stack>

//숫자를 입력받는데 0을 입력받으면 이때까지 입력받았던 0이외의 숫자중 마지막 숫자를 삭제한다.
//이는 후입선출을 기반으로하는 자료구조 stack을 사용하여 해결해본다.

using namespace std;

stack<int> st;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x != 0){
            st.push(x);
        }
        else{
            st.pop();
        }
    }
    int sum = 0;
    while(st.size() > 0){
        //for문의 조건을 i < st.size()로 했더니 가장 먼저 들어간 값을 탐색하지 않았다.
        //이는 for문의 마지막 구문으로 st.pop()을 수행한 결과 st.size()의 값이 변화햇기 때문이다.
        //이를 해결하기 위해선 1.초기 stack의 크기를 유지 2.stack의 사이즈가 0이 될때까지 pop 3.
        sum += st.top();
        st.pop();
    }
    cout << sum;
}