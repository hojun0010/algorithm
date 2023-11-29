//1:47 - 2:05
#include <iostream>

using namespace std;
//덩치를 비교하는데 키와 몸무게가 모두 커야 A보다 B의 덩치가 더 크다라고 할수있다.
//그렇다면 어떤식으로 비교를 진행해야하는가? 시간제한은 1초 n<= 50 이므로 O(n^5) 이상도 가능할듯?
//같은 순위의 A,B가 있다고 할때 C라는 사람이 A보다 덩치가 크고 B보다 덩치가 작은것이 가능한가? 가능
//자신보다 덩치가 큰사람을 세는것 => 해봣자 O(n^2)?
//1회 실패 2회 성공 
//출력 형태 고려 안함
int n;
int ans[50];
int arr[50][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n ; i++){
        int x,y;
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }
    for(int i=0; i < n; i++){
        int now_x = arr[i][0];
        int now_y = arr[i][1];

        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int comp_x = arr[j][0];
            int comp_y = arr[j][1];

            if(now_x < comp_x && now_y < comp_y){
                ans[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i]+1;
        if(i != n-1) cout << " ";
    }
}