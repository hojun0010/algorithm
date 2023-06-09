#include <iostream>
#include <vector>

using namespace std;
//DP���� - n��° ������ Ǯ������ �� ���ܰ��� ������� �ʿ��Ѱ�? 
//-> �ʿ��ϴٸ� �츮�� ���� ��� ������� �����ؼ� �̷��� ������� ���Ұ��̴�.
//�̸� ���� �ʿ��� ��� ��� ����� �迭 �� ���Ϳ� �����ؾ��Ѵ�.
//���� �ƿ� �츮�� ���ϴ´��� ���������� Ž���Ѵ�. ���ϴ� ��ǲ�� 10�̶�� ��ǲ�� 1���� ���� ����ؼ� 
//ex) ��ǲ�� 5�϶��� 3+A, 4+B �߿� �ּڰ��� ��ǲ�� 5�϶��� ��������� �����Ѵ�.
int main()
{
    int n;
    int num = 0;
    int val = 0;
    bool b = false;
    cin >> n;

    vector<vector<int>> vec1;
    vector<int> vec2;

    val = n;
    if(val%3 == 0){
        if(val/3 == 1){
            b = true;
        }
        vec2.push_back(val/3);
    }
    if(val%2 == 0){
        if(val/2 == 1){
            b = true;
        }
        vec2.push_back(val/2);
    }
    vec2.push_back(val-1); 
    vec1.push_back(vec2);
    vec2.clear();
    num++;   

    while(true){
        if(b == true){
            break;
        }
        for(int i = 0; i < vec1[num-1].size(); i++){
            val = vec1[num-1][i];
            if(val % 3 == 0){
                if(val/3 == 1){
                    b = true;
                    break;
                }
                vec2.push_back(val/3);
            }
            if(val % 2 == 0){
                if(val/2 == 1){
                    b = true;
                    break;
                }
                vec2.push_back(val/2);
            }
            vec2.push_back(val-1);       
        }
        vec1.push_back(vec2);
        vec2.clear();
        num++;
    }
    cout << num;
}