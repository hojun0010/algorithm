//2:25

#include <iostream>

using namespace std;
int n;
char arr[20000][50];

void mergesort(int a,int b){
    int left = a;
    int mid = (a+b)/2;
    int right = b;

    mergesort(left,mid);
    mergesort(mid+1,right);

    merge(left,mid+1,mid-left+1,right-mid);
}
void merge(int l,int r,int l_len, int r_len){
    int i = l; //왼쪽 배열 접근
    int j = r; //오른쪽 배열 접근
    int k = 0; //새 배열 접근

    char *(new_arr[50]) = new char[l_len+r_len][50];
    while(i < l+l_len || j < r+r_len){
        if(compare(arr[i],arr[j])){ //좌측의 우선순위가 더높다면(앞에 넣어야한다면)

        }

    }

}
bool compare(char a[], char b[]){ //a가 b보다 우선순위가 더 높다면(순위의 크기가 더 작다면) true, 아니면 false

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

}