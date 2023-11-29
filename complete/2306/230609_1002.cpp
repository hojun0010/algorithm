#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//2개의 좌표가 주어지고 그 좌표에서부터 각각 주어진 거리만큼의 원을 그린후 두 원이 겹치는 부분에서 정수값을 출력한다.
//거리값은 정확한 값이므로 원 안은 포함되지 않고 두 원의 교점의 개수를 구한다.
//두개의 원이 서로 교점을 가지는 조건 ->
//2개 or 1개(한점에서 교점) or 0개(만나지 않는 경우)
//2개 : 두 점 사이의 거리가 각각의 원의 반지름을 더한 값보다 작은경우(작은 원의 중심점이 큰 원 밖에 있는 경우), 
//있을수 있는 위치가 무한대인 경우는 존재하는가? -> 두 원이 정확히 일치하는 경우

//문제점 long double과 int 타입끼리의 비교가 제대로 안이뤄졌다.? or 제곱의 연산으로 ^2을 사용한 결과값이 이상한 값을 나타냈다. -> 이후 제곱할땐 pow를 사용할것
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int T;
    long double x1,y1,r1,x2,y2,r2;
    vector<long double> s;
    vector<long double> b;
    vector<long double> ans;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long double dis = sqrt(pow(x1-x2,2)+pow(y1-y2,2)); //두 점 사이의 거리 n1-n2의 범위는 최대 2만 = 2*10^4까지 -> 제곱의 범위는 4*10^8 =4억 int 범위가 가능


        if(r1 == r2){ //두 원의 크기가 같을때
            if(x1==x2 && y1 == y2){ //두 원이 완전히 겹침
                ans.push_back(-1);
            }
            else if(dis < r1+r2){ //두 점사이의 거리가 두 원의 반지름 합보다 작으면
               ans.push_back(2);
            }
            else if(dis == r1+r2){ // 두 점사이의 거리와 두 원의 반지름의 합이 같으면
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        else{
            if(r1 > r2){
                b.push_back(x1);
                b.push_back(y1);
                b.push_back(r1);
                s.push_back(x2);
                s.push_back(y2);
                s.push_back(r2);
            }
            else{
                s.push_back(x1);
                s.push_back(y1);
                s.push_back(r1);
                b.push_back(x2);
                b.push_back(y2);
                b.push_back(r2);
            }
            if(dis+s[2] < b[2] || dis > s[2]+b[2]){ 
                //교점이 생기지 않는 경우 -> 1. 점 사이의 거리+작은원의 반지름 < 큰원의 반지름(작은원은 큰원 내부에 속한다) 2.두 원이 떨어져 있을때
                ans.push_back(0);
            }
            else if(dis+s[2] == b[2] || dis == s[2]+b[2]){
                //두 원이 서로 접하는 경우 -> 1.점 사이 거리+작은 원의 반지름 == 큰원의 반지름(작은 원이 큰 원의 내부에서 접한다) 2.점 사이 거리 == 두 원의 반지름 합(외부에서 접한다.)
                ans.push_back(1);
            }
            else{ //나머진 모두 2개의 교점이 생성
                ans.push_back(2);
            } 
            
        }
        b.clear();
        s.clear();
    }
    for(int i = 0; i < T; i++){
        cout << ans[i];
        if(i != T-1){
            cout << "\n";
        }
    }
}