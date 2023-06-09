#include <iostream>
#include <vector>
#include <set>
#include <algorithm>  

using namespace std;
//1초 + 128MB -> 보통 1억정도
//set을 이용한 문제풀이 -> 시간초과 c++ 에서 set은 binary tree로 구현된다 -> insert에 O(n/2)? search에 O(n/2)? * m
//100000개 안에 100000개의 수가 존재하는지 판단 -> 최대 O(n+m)까지 -> 새로운 구조를 만들어야하나?
//정수 범위는 -2^31 <= x < 2^31까지 -> 2^32개? -> 2^20 * 2^12 -> 4096MB
//C++ 의 sort()는 intro sort 방식으로 O(nlogn)
//sort()후 m개의 숫자에 대해 각각의 이진탐색  -> O(mlogn)
//vector를 sort한 후 이진탐색을 통해 검색 -> 시간초과 -> 왜? O(nlogn + mlogn)이 아닌가?\

//해결
//많은 양의 입출력을 수행하는 경우 cin.tie(null)이 필수이다.
//또한 endl 출력의 경우 줄바꿈 역할 이외에 flush 연산도 수행된다. 이는 가벼운 연산이 아님과 더불어 수만번의 누적 수행은
//tle로 이어질수 있다.
int main(){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  int n,m;

  cin >> n;

  vector<long> vec;
  vector<int> sol;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    vec.push_back(x);
  }
  sort(vec.begin(),vec.end());

  cin >> m;
  for(int i = 0; i < m; i++){
    bool b = false;
    int y; 
    cin >> y;

    int in = 0;
    int out = vec.size()-1;
    int index = 0;
    while(in <= out){
      index = (in+out)/2;
      if(y == vec[index]){
        b = true;
        break;
      }else if(y > vec[index]){
        in = index+1;
      }else if(y < vec[index]){
        out = index-1;
      }
    }
    if(b == true){
      sol.push_back(1);
    }else{
      sol.push_back(0);
    }
  }
  for(int i = 0; i < m; i++){
    cout << sol[i] << "\n";
  }
}