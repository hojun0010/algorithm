#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N;
int map[25][25];
int visit[25][25] = {0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> vec;
int cnt = 0;
string str;

int DFS(int x, int y){
  int max = 0;
  visit[x][y] = 1;
  for(int i = 0; i < 4; i++){
    int n_x = x + dx[i];
    int n_y = y + dy[i];
    if(n_x >= 0 && n_y >= 0 && n_x < N && n_y < N){
      if(visit[n_x][n_y] != 1){
        int value = DFS(n_x,n_y);
        if(max < value){
          max = value;
        }
      }
    }
  }
  max++;
  return max;
}

int main(){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> str;
    for(int j = 0; j < N; j++){
      cout << "(" << i << " , " << j << " ) : " << map[i][j] <<"\n";
      cout << "str : " << str[j] << "\n";
      map[i][j] = (int)(str[j]);
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j <N; j++){
      if(visit[i][j] == 0 && map[i][j] == 1){
        cnt++;
        vec.push_back(DFS(i, j));
      }
    }
  }
  cout << "cnt : " << cnt << "\n";
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << "\n";
  }
  
}
