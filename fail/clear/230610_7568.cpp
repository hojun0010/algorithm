#include <iostream>
#include <vector>

using namespace std;
//덩치가 큰 사람을 구하는데 키와 몸무게가 모두 커야 A가 B보다 덩치가 크다라고 정의할 수 있다 둘 중의 하나라도 작을경우 A와 B의 덩치 순위는 같아진다.
//즉 덩치 순위가 높은 사람은 낮은 순위의 어떤 사람보다 커야 하며 이는 낮은 덩치 순위 그룹의 최대 몸무게와 최대 신장보다 커야한다.
//따라서 덩치 순위가 같은 사람들끼리 묶는것을 중점으로 문제를 해결한다.
//높은 순위는 낮은 순위의 최대값보다 무조건 크고 낮은 순위는 높은 순위의 최소값보다 무조건 작다. -> 해결못함
//2번째 풀이 모든 경우를 탐색 -> O(n(n-1)) = O(n^2) N은 최대 50이므로 시간초과는 상관없다
//해결 못함... 비교는 하되 등수를 어떻게 처리할것인가에서 어려움을 겪었다. 탐색하는 도중 앞에 결정된 순위를 어떻게 변화시킬것인가
//하위 순위를 결정하기 위해 동일 등수의 사람 수를 어떻게 유지시킬것인가 -> 예시 코드로 공부

//-> 결국 현재 사람의 정보를 다른 모든 사람의 정보와 비교한다 이때 자신보다 모든 정보가 큰 사람의 수+1 만큼 자신의 등수가 된다.
//


vector<pair<int,int>> stu;
vector<vector<int>> vec;
vector<int> scale;  

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i <t ; i++){
        int x,y;
        cin >> x >> y;
        stu.push_back(make_pair(x,y));
    }
    for(int i = 0; i < t; i++){
        int h,w;
        h = stu[i].first;
        w = stu[i].second;
        for(int j = 0; j < i; j++){

        }
    }


}