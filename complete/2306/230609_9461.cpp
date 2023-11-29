#include <iostream>
#include <vector>

using namespace std;

//삼각형이 계속 붙는데 생성하는 정삼각형은 현재 모양에서 붙을수 있는 가장 긴변을 본인의 변으로 갖는 삼각형이 붙는다.
//규칙이 존재하는가?
//1 1 1 2 2 3 4 5 7 9 12 16
//1 2 3 4 5 6 7 8 9 10 11 12
//-> 5번째까지는 불규칙? 이후 p(n) = p(n-1)+p(n-5)

//1번째 제출 -> 시간초과 - why? -> 재귀함수라서 시간이 많이 걸린듯? 1초 제한시간에 P(100)까지 범위 
//-> 해결법 1~n까지의 값을 미리 저장하자, p(n)을 구하기 위해선 p(n-1)-p(1,2,3,4,5) 까지의 값이 모두 필요하다 -> 즉 모든 값을 구해도 손해가 아니다?

//2번째 제출 -> 틀렸습니다 - why? -> 답의 범위가 문제 답의 최대값 p(100)은 int의 범위값을 넘어갈수있다. 이를 어떻게 알아내나
//-> 값을 저장하는 배열을 모두 출력해봐서 중간에 오버플로우가 발생하는지 판단하는것이 가장 쉽다.

vector<long long> ans;
long long value[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    value[1] = 1;
    value[2] = 1;
    value[3] = 1;
    value[4] = 2;
    value[5] = 2;

    int t;
    cin >> t;
    for(int i = 0; i < t ; i++){
        int n;
        cin >> n;
        if(n <= 5){
            ans.push_back(value[n]);
        }
        else{
            for(int j = 6; j <= n; j++){
                value[j] = value[j-1]+ value[j-5];
            }
            ans.push_back(value[n]);
        }
    }
    for(int i = 0; i < t; i++){
        cout << ans[i];
        if(i != t-1){
            cout << "\n";
        }
    }

}