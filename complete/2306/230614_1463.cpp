#include <iostream>

using namespace std;

//x가 1이 되기 위해서 우리는 3으로 나누던지 2로 나누던지 1을 빼던지 선택할수있다. 1이 되기 위한 최소의 연산수를 구하는것
//그렇다면 어떤 경우에 3을 나누는게 유리하고 2로 나누는게 유리할것인가
//1.모든 경우를 미리 계산해놓는 건 어떤가?
//N의 크기는 10^6 = 1000000 p(n)을 n이 되기 위해 1부터 시작하는 최소 연산의 수라고 한다면
//p(n) = min(p(n/3)+1,p(n/2)+1,p(n-1)+1)이 된다.
//p(n/3),p(n/2),p(n-1)은 p(n)을 구하기전 모두 구해져 있으므로 O(1)이 소요되며 총 소요시간은 O(N) ~ O(10^6) 이다. 한계시간은 0.15초
int arr[1000001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    for(int i = 1; i <= x; i++){
        if(i == 1) {
            arr[i] = 0;
        }
        else if(i % 2 == 0 && i % 3 == 0){
            arr[i] = min(min(arr[i/2],arr[i/3]),arr[i-1])+1;
        }
        else if(i % 2 == 0 && i % 3 != 0){
            arr[i] = min(arr[i/2],arr[i-1])+1;
        }
        else if(i%2 != 0 && i%3 == 0){
            arr[i] = min(arr[i/3],arr[i-1])+1;
        }else{
            arr[i] = arr[i-1]+1;
        }
    }
    cout << arr[x];
}