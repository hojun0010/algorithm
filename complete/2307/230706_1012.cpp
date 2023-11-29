#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
//bfs 로 해결
//순위 코드와의 차이점
//순위 코드는 map[52][52] 배열 하나만을 유지하여 dfs 및 visited를 구현하였다.
//map의 값이 false라면 방문한것으로 가정, 방문한것과 연결되지 않은것은 false로 동일하게 관리한다. 이는 한번 방문한 노드는 연결되지 않을것으로 고려해도 상관없기 때문
//dx,dy를 이용하여 다음 x,y값을 구한뒤 그 map[x][y]==true 라면 dfs(x,y)로 재탐색
//의문 : dfs가 그룹내의 모든 요소를 탐색하는가? 탐색할듯하다. 
//-> dfs는 root node부터 left node(제일 level이 낮은) 까지 탐색 그다음 level이 높은 node까지 탐색
//필요한것은 main문에서 dfs가 실행되는 횟수를 구하는것 + 각 node를 이동하는 비용이 모두 1로 같기에 map만으로 구현 가능하다.
int t;
int n,m,k;
int arr[50][50] = {0};
int visited[50][50] = {0};
int cnt = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int,int>> que;

void bfs(int a, int b){
    que.push(make_pair(a,b));
    visited[a][b] = 1;

    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int n_x = x+dx[i];
            int n_y = y+dy[i];
            if(n_x < 0 || n_x > n-1 || n_y < 0 || n_y > m-1) continue;
            else{
                if(visited[n_x][n_y] == 0 && arr[n_x][n_y] == 1){
                    visited[n_x][n_y] = 1;
                    que.push(make_pair(n_x,n_y));
                }
            }
        }   
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
   
    for(int i = 0; i < t; i++){
        cin >> m >> n >> k;
        for(int h = 0; h < k; h++){
            int a,b;
            cin >> b >> a;
            arr[a][b] = 1;
        }
        for(int h = 0; h < n; h++){
            for(int j = 0; j < m; j++){
                if(visited[h][j] == 0 && arr[h][j]){
                    bfs(h,j);
                    cnt++;
                }
            }
        }
        cout << cnt;
        if(i != t-1) cout << "\n";
        cnt = 0;
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
    }
}