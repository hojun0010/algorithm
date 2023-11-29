#include <iostream>
#include <vector>

using namespace std;
vector<int> ans;
vector<int> pro;

//인덱스를 순환형태로 탐색하며 구한다. 삭제하는 경우 벡터의 크기가 변하는것을 고려해야하며 또한 인덱스 탐색을 위한 변수가 벡터의 크기보다 커질 경우
//벡터의 크기를 빼는 연산이 필요하다. erase() 함수의 경우 인자가 iterator 이므로 k번째 원소 즉 인덱스가 [k-1]인 원소를 접근해야한다.
// 
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        pro.push_back(i+1);
    }
    int m = k-1;
    while(pro.size() > 0){
        ans.push_back(pro[m]);
        pro.erase(pro.begin()+m);
        m += k-1;
        //1 4  
        if(pro.size() == 0){
            break;
        }
        while(pro.size() <= m){
            m -= pro.size();
        }
    }
    cout << "<";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size()-1){
            cout << ", ";
        }
    }
    cout << ">";
}