#include <iostream>
#include <vector>
#include <string>
//https://www.acmicpc.net/problem/1181
//제한시간2초 -> 20억=2*10^9 n=20000 m=50 이므로 대충 O(n^3이하?) n^2 = 4*10^8
//각 단어를 vector에 저장 우선 길이 비교 후 한글자씩 판단
// vector vs 배열(인덱스=0 일때 각 단어의 길이를 저장한 배열)
// 병합 정렬을 사용한다. 
using namespace std;

int n;
vector<string> vec;
vector<string> ans;
string word;

void merges(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (vec[i].compare(vec[j]) > 0) {
			ans[k++] = vec[j++];
		}
		// 양쪽 리스트에서 최솟값을 비교했는데 오른쪽 리스트가 더 컸을 경우
		// 그대로 왼쪽 리스트의 최솟값이 결과배열에 내려오면 됩니다.
        else if(vec[i].compare(vec[j]) == 0){
            
        }
		else {
			ans[k++] = vec[i++];
		}
	}
	// 오른쪽 리스트에 아직 결과배열에 들어가지 못한 값이 있으면 그대로 넣어줍니다.
	if (i > mid) {
		while (j <= right) {
			ans[k++] = vec[j++];
		}
	}
	else { // 그림의 (6)번 과정
		while (i <= mid) {
			ans[k++] = vec[i++];
		}
	}

	// 다시 원래 배열에 옮겨담는 작업
	for (int a = left; a <= right; a++) {
		vec[a] = ans[a];
	}
}

void partition(int left, int right) {
	int mid;
	// 두개로 분할하고, 병합하는 과정
	// 병합 함수 merges를 보면 알 수 있듯이, while문 등으로 정렬하면서 병합하게 된다.
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merges(left, right);
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        vec.push_back(word);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 50; j++){
            
        }
    }
}
//O(nlogn)의 시간으로 해결해야 한다. -> merge sort의 방식으로 merge를 재정의하여 해결한다. 
//merge sort의 구조 => 분리와 결합 => 재귀함수를 이용하여 sort 함수를 정의(중간값을 기준으로 좌측과 우측 범위를 재귀적으로 sort에 호출, 이후 좌측과 우측을 결합한다.)
//결합 함수는 따로 정의되며 모든 분리와 결합은 본래의 단어 배열 하나만을 가지고 정의된다. 
//즉 하나의 배열을 갖고 좌,우측 인덱스 등을 유지하며 분리와 결합을 진행한다.
//결합 방식은 매개변수로 주어진 좌측,우측 배열 길이를 갖고 arr[left_len+right+len][51] (글자 길이는 최대 50글자, 즉 단어 하나가 1개의 row에 저장된다.)
//이라는 결합된 배열을 저장할 임시 배열을 선언한다. 
//,우측 인덱스 시작부터 비교, 순위가 더 높은것을 임시 배열에 저장하고 더 높은 순위가 발견된 배열의 다음 인덱스와 다른 배열의 인덱스를 그대로 두고 비교를 계속한다.
//어느 한쪽의 배열의 모든 단어가 비교에 사용되었다면 남은 배열의 모든 단어는 왼쪽의 가장 낮은 순위의 단어보다 낮음으로 임시 배열에 그대로 추가한다.
//모든 비교가 끝나면 임시 배열의 값을 본래의 배열의 원래 위치에 복사한다
//strcpy 함수 사용: char* strncpy(char* dest, const char* origin, size_t n); 
//모든 함수는 매개변수로 받는 단어 배열을 arr[N][51]이라 하면 char (*arra)[51]을 매개변수로 받는다. (본래 배열의 row에 대한 포인터 변수를 매개변수로 사용,즉 포인터 변수 배열)
//단어의 길이를 비교하기 위한 함수 compare()을 재정의. 
//1순위 : 단어 길이, 이후 첫글자부터 비교하며 앞 매개변수가 더 높은 순위일경우 true, 아니면 false를 반환
//https://loding.tistory.com/entry/%EB%B0%B1%EC%A4%80C%EC%96%B8%EC%96%B4-1181%EB%B2%88-%EB%8B%A8%EC%96%B4-%EC%A0%95%EB%A0%AC
