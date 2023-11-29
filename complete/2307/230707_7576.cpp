#include <iostream>
#include <queue>
#include <numeric>
#include <cstring>
#include <iomanip>
//현재 밭에서 0의 값을 가진 모든 노드들에 대해 1의 값을 가진 노드로부터의 path가 존재한는가?
//bfs를 수행 노드를 탐색할때마다 해당 노드의 값을 1로 변경 탐색 완료후 0이 존재하면 -1 이다.
//해결 못함 -> 시간초과
//어려웠던점 
//노드끼리의 패스를 뭘 기준으로 만들것인가(토마토가 자란 곳부터 덜자란 곳까지 or 덜자란 곳부터 자란곳까지)
//토마토가 자란곳에서 bfs를 수행하는데 어떤 노드는 다른 토마토가 자란곳에서의 path가 더 길이가 짧은 곳이 있을때 이를 어떻게 구분할것인가

//답을 보고 : 최대 1000*1000이므로 10억이 1초임을 생각하면 O(n^3)보다는 작아야한다.
//모든 토마토에 대해서 각각 bfs를 돌리면 안된다? -> bfs 단 한번으로 해결이 가능하다 어떻게?
//나의 방법 : 하나의 1인 노드에 대해 모든 노드를 포함하는 트리를 만들고 그 다음 1인 노드에 대해서도 반복한다.
//이는 현재 1의 노드에 대해 멀리 떨어져있는 노드들 즉 다른 1인 노드로부터 더 가까운 노드들까지 탐색하게 된다
// 해결법 : 미리 다른 1인 노드들도 queue 삽입해놓는다 즉 1인 노드들 위에 root node가 있다고 가정하고 dfs 트리를 만드는 것이다. -> 해결완료
// 원래의 방법 nxm개의 노드에 대해 한개의 노드에서 bfs를 진행할경우 배열의 경우 O(n*m)

using namespace std;

int n,m;
int arr[1000][1000]; //초기 토마토의 정보 저장
int date[1000][1000]; //성장 날짜를 업데이트
int visited[1000][1000]; //dfs 과정중 방문된 좌표를 유지
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int ans = 0; //최소 성장 날짜
queue<pair<pair<int,int>,int>> que; //(x,y), tree depth

void bfs(){ //1이 하나도 없는 경우 -1
    while(!que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int depth = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++){
            int n_x = x+dx[i];
            int n_y = y+dy[i];
            if(n_x < 0 || n_x > n-1 || n_y < 0 || n_y > m-1) continue;
            else{
                if(arr[n_x][n_y] != -1 && visited[n_x][n_y] == 0){
                    if(arr[n_x][n_y]==1) continue; //다음 탐색 노드가 1이라면 다음 노드부터는 1인 노드부터 탐색을 시작하는것이 더 빨리 전달된다.
                    que.push(make_pair(make_pair(n_x,n_y),depth+1));
                    if(date[n_x][n_y] > depth+1) date[n_x][n_y] = depth+1; //depth는 queue에서 빼낸 좌표의 성장 날짜, 현재 저장된 성장 날짜보다
                    //더 작은 성장 날짜로 도달될수 있는 1의 값을 가진 노드로부터의 path를 찾았다면 현재 노드의 성장 날짜를 업데이트
                    visited[n_x][n_y] = 1; //
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    int first_zero_cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            arr[i][j] = a;
            if(a == 0) first_zero_cnt++;
            if(a == 1) date[i][j] = 0;
            else date[i][j] = 5000000;
        }
    }
    if(first_zero_cnt == 0){ //0이 하나도 없는 케이스
        cout << 0;
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1) {
                    que.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        bfs();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] != -1 && date[i][j] == 5000000){
                    cout << -1;
                    return 0;
                }
                else if(arr[i][j] != -1){
                    if(ans < date[i][j]) ans = date[i][j];
                }
            }
        }
        cout << ans;
    }
    
    
}