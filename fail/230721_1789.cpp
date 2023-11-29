//3:55

#include <iostream>
using namespace std;
unsigned int s;

//s가 주어졌을때 s를 서로다른 n개의 자연수의 합으로 표현하는 n개의 자연수들 중 최대값 n을 구하여라
//n은 가장 크게 -> 1부터 시작해서 가장 작게 만들수 있는합 + n = s가 되도록 할때 n은 솔루션이다?
//O(2^20) -> 42억? 2초에 대략 2억이나 시간은 O(logn)이 필요

//n개의 자연수들 중 최대값 n이 아니라 갯수가 n개라는 것이였다... -> 
//
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    //1+2+3+4+5+6+7+ ... a => (a+1)이 a/2개 존재 => a(a+1)/2 -> 주어진 n을 반씩 잘라가면 공식에 대입하여 값을 계산? 
    
    unsigned int n = s/2;
    if(n == 0) n = 1;
    unsigned int right = s;
    unsigned int left = 1;
    while((s-n-1)*2/(n+1) >= n || 2*s/(n+1) < n){ // sum <= s < sum+n+1 일때 break
        if(n > 2*s/(n+1)){ //sum을 줄여야한다 -> n을 줄인다
            right = n;           
        }
        else{
            left = n; 
        }   
        n = (left+right)/2;
    }
    cout << n;
}