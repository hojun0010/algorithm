#include <iostream>
#include <vector>
#include <string>
using namespace std;

//1. dfs�� �õ�
//�̿� -> �ش� bfs ���� /��Ʈ queue ���

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