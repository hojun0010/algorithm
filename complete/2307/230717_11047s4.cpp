//3:41 - 3:48
#include <iostream>

using namespace std;
int n,k;
int arr[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }
    int cnt = 0;
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] <= k) {
            cnt = k/arr[i];
            k -= cnt * arr[i];
            ans += cnt;
            cnt = 0;
        }
    }
    cout << ans;  
}