#include <iostream>

using namespace std;
//2xn 크기의 직사각형을 2x1,1x2의 직사각형으로 채우는 방법의 수 p(n)을 2xn의 직사각형을 채우는 방법의 수라고 하면
//p(n) = p(n-1) + p(n-2) (n>= 3)-> 2xn의 직사각형에 2x1을 젛으면 2x(n-1)만이 남고 2xn에 1x2를 넣으면 1x2의 공간과 2x(n-2)의 공간이 남는다.
// 점화식이 생성되었으므로 dp로 해결 -> 틀렷습니다?
//점화식을 통해 순서대로 구하다보면 40번째즘에서 int 값을 넘어가버리는 오버플로우가 발생한다. 그래서 문제 자체에서 10007%로 구하라고 주어졌다.
//의문 : 배열을 int가 아닌 더 큰 범위의 배열로 선언하면 오버플로우가 발생하지 않을까?

long long arr[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n;i++){
        if(i==1) arr[i] = 1;
        else if(i==2) arr[i] = 2;
        else arr[i] = (arr[i-1]+arr[i-2])%10007;
    }
    cout << arr[n];
}