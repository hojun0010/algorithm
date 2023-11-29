//3:20 - 3:36
//각 사람이 돈을 뽑는데 걸리는 시간의 합이 최소로 되게 하라
// ㄴ 시간 크기를 오름차순으로 정렬하는것이 솔루션인가? => yes => solution => a1 + a1 + a2 + a1 + a2 + a3 .... 가 최소가 되게 해야한다.
// 즉 더해지는 횟수가 많은 것부터 차례대로 작은값이 지정되어야한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> vec;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;

    for(int i = 0; i <n ; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());

    int sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        //sum += sum + vec[i]; -> 왜틀렸는가? 우항의 sum = 1부터 i-1번째 사람이 인출하는데 걸리는 시간의 합?

        //n번째 사람이 걸리는 시간 = n-1번째 사람이 인출하는데 걸리는 시간 + n번째 사람만이 인출하는데 걸리는 시간 => arr[0...n-1]의 합
        //arr[0] + arr[0,1] + arr[0..2] ... + arr[0...n-1]?
        sum += vec[i];
        ans += sum;
    }
    cout << ans;
}