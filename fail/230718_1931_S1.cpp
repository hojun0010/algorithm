//1:59 - 2:18 
#include <iostream>

//https://www.acmicpc.net/problem/1931
//현재 시간에서 가장 가깝게 시작하면서 가장 빨리 끝나는 회의를 선택한다.


//어려운점 : 병합정렬의 구현 -> 크기순으로 정렬할때 반환하는 배열을 새로 만들것인가? 아니면 원래 배열의 값을 바꿀것인가
// 원래 배열의 값을 바꾼다 결정 -> 병합 과정을 어떻게 구현할 것인가 이미 정렬된 두 배열을 어떻게 병합할것인가를 명확히 알지 못했다.

using namespace std;
int n;
int arr[100000][2];


void sort(int left, int right){

    int mid = (left+right)/2;

    mergesort(left,mid);
    mergesort(mid+1,right);

    merge(left,right,mid-left+1,right-mid);
}
void mergesort(int left,int right){ //
    
}
void merge(int left,int right,int l_len, int r_len){ //left부터 l_len 길이의 배열과 (left+right)/2 부터 r_len 길이의 배열을 서로 병합
    //{ 4 3 23 12 34 452 21 34 212 53 112}
    int mid = (left+right)/2;

    for(int i = 0; i < l_len; i++){
        if(left >= l_len && mid+1 < right){ //왼쪽 배열의 

        }
        if(arr[left][1] < arr[mid+1][1]){ //오른쪽 배열의 크기가 크면
            left++;
        }
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }

    
}