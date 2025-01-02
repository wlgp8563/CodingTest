//프로그래머스<같은 숫자는 싫어> 풀이 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//내가 생각한 push_back(벡터 끝에 원소를 추가한다)을 활용한 풀이.
/*1. 벡터 answer에 벡터 arr 첫번째 요소를 넣어두고 벡터 arr를 순환. 
2. index값은 i, j 두개로 설정
3. arr의 첫 요소는 이미 처음에 넣었기 때문에 i는 1부터 시작
4. 만약 arr[i] 요소와 answer[j], 즉 index 0번째 요소가 같다면 i값만 증가시키고 반복
5. 그렇지 않다면 다른 요소이므로 answer에 그 index에 해당하는 arr[i] 요소를 push_back 하고 j값 하나 증가
6. 반복문은 arr의 크기만큼 반복되고 종료되면 answer vector에는 순서를 유지하며 중복을 제거한 vector가 저장*/
vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	answer.push_back(arr[0]);

	for (int i = 1, j = 0; i < arr.size(); i++) {
		if (arr[i] == answer[j]) {
			continue;
		}
		else {
			answer.push_back(arr[i]);
			j++;
		}
	}
	return answer;
}

//다른 사람의 코드를 참고한 erase, unique 함수를 활용한 풀이
vector<int> solution(vector<int> arr)
{
	arr.erase(unique(arr.begin(), arr.end(), arr.end()));

	vector<int> answer = arr;
	return answer;
}