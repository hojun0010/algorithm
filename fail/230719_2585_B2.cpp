//3:58

//1회차 실패 -> ... line 19 if(m > arr[i])의 경우 m과 arr[i]가 같을경우 잔돈이 나올수 없다 보고 통과하게 된다...
#include <iostream>

using namespace std;
int m = 0;
int arr[6] = {500,100,50,10,5,1};
int sum = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    m = 1000-m;

    for(int i = 0; i < 6; i++){
        if(m == 0) break;
        if(m >= arr[i]){
            int cnt = m/arr[i];
            m -= arr[i]*cnt;
            sum += cnt;
        }
    }
    cout << sum;

}