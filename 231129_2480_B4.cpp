#include <iostream>

using namespace std;
int a,b,c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    int result = 0;
    if(a == b){
        if(b == c) result += 10000 + a * 1000;
        else result += 1000 + a*100;
    }
    else if(a > b){
        if(a == c || b == c) result += 1000 + c*100;
        else if(a > c) result += a * 100;
        else if(c > a) result += c * 100;
    }
    else{ // b> a
        if(b == c || a == c) result += 1000 + c*100;
        else if(b > c) result += b * 100;
        else if(c > b) result += c * 100;
    }
    cout << result;
}