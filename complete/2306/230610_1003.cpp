#include <iostream>
#include <vector>

using namespace std;
//피보나치의 규칙
//1.재귀함수로 구현 -> 시간초과
//2.dp로 구현한다.

vector<int> test;
pair<long long,long long> arr[41];
int maxTest = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int x;
        cin >> x;
        test.push_back(x);
        if(maxTest < x){
            maxTest = x;
        }
    }
    for(int i = 0; i <= maxTest; i++){
        if (i == 0){
            arr[i] = make_pair(1,0);
        }
        else if(i == 1){
            arr[i] = make_pair(0,1);
        }
        else{
            arr[i] = make_pair(arr[i-1].first+arr[i-2].first, arr[i-1].second+arr[i-2].second);
        }
    }
    for(int i = 0; i < test.size(); i++){
        cout << arr[test[i]].first << " " << arr[test[i]].second;
        if(i != test.size()-1){
            cout << "\n";
        }
    }
}