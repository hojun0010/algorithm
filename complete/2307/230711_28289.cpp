//4:24 -> 4:31

#include <iostream>

using namespace std;

int n;
int ans1,ans2,ans3,ans4 = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >>c;
        switch(a){
            case 1 : {
                ans4++;
                break;
            }
            default : {
                if(b == 3) ans2++;
                else if(b==4) ans3++;
                else ans1++;
            }
        }
    }
    cout << ans1 << "\n" << ans2 << "\n" << ans3 << "\n" << ans4;
}