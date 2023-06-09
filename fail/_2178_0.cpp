#include <iostream>
#include <vector>
#include <string>
using namespace std;

//1. dfs로 시도
//미완 -> 해답 bfs 쓸것 /힌트 queue 사용

int n,m;
int arr[100][100] = {0};
int arr2[100][100] = {0};

int main(){
  ios::sync_with_stdio(0); 
  cin.tie(0);
  
  vector<vector<int>> sol;

  cin >> n >> m;
  for(int i=0; i < n; i++){
    for(int j=0; j < m; j++){
      int x;
      cin >> x;
      arr[i][j] = x;
    }
  }
  
}

int cal(int x,int y){
  if(x == n && y == m){
    return 0;
  }
  int num1,num2,num3,num4;
  if(x >= 1){
    num1 = 
  }
  
}