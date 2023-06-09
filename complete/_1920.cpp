#include <iostream>
#include <vector>
#include <set>
#include <algorithm>  

using namespace std;
//1�� + 128MB -> ���� 1������
//set�� �̿��� ����Ǯ�� -> �ð��ʰ� c++ ���� set�� binary tree�� �����ȴ� -> insert�� O(n/2)? search�� O(n/2)? * m
//100000�� �ȿ� 100000���� ���� �����ϴ��� �Ǵ� -> �ִ� O(n+m)���� -> ���ο� ������ �������ϳ�?
//���� ������ -2^31 <= x < 2^31���� -> 2^32��? -> 2^20 * 2^12 -> 4096MB
//C++ �� sort()�� intro sort ������� O(nlogn)
//sort()�� m���� ���ڿ� ���� ������ ����Ž��  -> O(mlogn)
//vector�� sort�� �� ����Ž���� ���� �˻� -> �ð��ʰ� -> ��? O(nlogn + mlogn)�� �ƴѰ�?\

//�ذ�
//���� ���� ������� �����ϴ� ��� cin.tie(null)�� �ʼ��̴�.
//���� endl ����� ��� �ٹٲ� ���� �̿ܿ� flush ���굵 ����ȴ�. �̴� ������ ������ �ƴ԰� ���Ҿ� �������� ���� ������
//tle�� �̾����� �ִ�.
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