//1:51 - 2:20

//2회 시도 -> 메모리 초과
#include <iostream>
#include <queue>

using namespace std;
int arr[100][100];
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char cha[100];

queue<pair<pair<int,int>,int>> que;

int bfs(int a, int b){
    que.push(make_pair(make_pair(a,b),1));
    while(!que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int path = que.front().second;
        if(x == n-1 && y == m-1) return path;
        que.pop();
        arr[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int n_x = x+dx[i];
            int n_y = y+dy[i];
            if(arr[n_x][n_y] == 1 && (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) == false) que.push(make_pair(make_pair(n_x,n_y),path+1));
        }
    }
    return -1;
}   
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> cha;
        for(int j =0; j < m; j++){
            arr[i][j] = cha[j] - '0';
        }
    }
    cout << bfs(0,0);
}