#include <iostream>

//해결 : 현재 시각에서 분을 더한값을 출력하는 방법을 서술해야한다. 60분을 넘겼을때 시가 변하는것과 23:59 다음 00:00 으로 바뀌는것을 예외처리해야한다.
using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int t,m,n;
    cin >> t >> m;
    cin >> n;

    int ct,cm;
    ct = t;
    cm = m+n;
    while(cm >= 60){
        if(cm >= 60){
        ct++;
        cm -= 60;
        }
        if(ct >= 24){
            ct -= 24;   
        }
    }

    cout << ct << " " << cm; 
}