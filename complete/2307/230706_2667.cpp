#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//dfs를 사용 하나의 path가 하나의 그룹
//의문 : dfs는 한그룹을 무조건 탐색하는가? -> 모르겟다.
//bfs는 무조건 연결된 모든 노드들을 탐색한다. -> bfs 해결해보자

int n;
int arr[25][25];    
int visited[25][25];
queue<pair<int,int>> que;
int cnt_group = 1;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<int> vec;

void bfs(int a, int b){
    que.push(make_pair(a,b)); //현재의 노드를 que에 삽입
    visited[a][b] = 1;
    while(!que.empty()){ // 현재 노드에서 탐색 시작
        int x = que.front().first; 
        int y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int n_x = x+dx[i];
            int n_y = y+dy[i];
            if(n_x < 0 || n_x > n-1 || n_y < 0 || n_y > n-1){
                continue;
            }
            else{
                if(visited[n_x][n_y]==0 && arr[n_x][n_y] == 1){ //(a,b)를 root node로 갖는 graph를 찾을것이다.
                    visited[n_x][n_y] = 1;
                    que.push(make_pair(n_x,n_y));
                    cnt_group++;
                }
            }
        }     
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;
    for(int i = 0; i < n; i++){
        char* line = new char[n];
        cin >> line;
        for(int j = 0; j < n; j++){
            char num = line[j];
            arr[i][j] = num -'0';
        }
        delete [] line;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0 && arr[i][j] == 1){
                bfs(i,j);
                vec.push_back(cnt_group);
                cnt_group = 1;
            }
        }
    }

    cout << vec.size() << "\n";
    sort(vec.begin(),vec.end());
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if(i != vec.size()-1){
            cout << "\n";
        }
    }
}