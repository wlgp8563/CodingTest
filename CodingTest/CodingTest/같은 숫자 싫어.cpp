//���α׷��ӽ�<���� ���ڴ� �Ⱦ�> Ǯ�� 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//���� ������ push_back(���� ���� ���Ҹ� �߰��Ѵ�)�� Ȱ���� Ǯ��.
/*1. ���� answer�� ���� arr ù��° ��Ҹ� �־�ΰ� ���� arr�� ��ȯ. 
2. index���� i, j �ΰ��� ����
3. arr�� ù ��Ҵ� �̹� ó���� �־��� ������ i�� 1���� ����
4. ���� arr[i] ��ҿ� answer[j], �� index 0��° ��Ұ� ���ٸ� i���� ������Ű�� �ݺ�
5. �׷��� �ʴٸ� �ٸ� ����̹Ƿ� answer�� �� index�� �ش��ϴ� arr[i] ��Ҹ� push_back �ϰ� j�� �ϳ� ����
6. �ݺ����� arr�� ũ�⸸ŭ �ݺ��ǰ� ����Ǹ� answer vector���� ������ �����ϸ� �ߺ��� ������ vector�� ����*/
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

//�ٸ� ����� �ڵ带 ������ erase, unique �Լ��� Ȱ���� Ǯ��
vector<int> solution(vector<int> arr)
{
	arr.erase(unique(arr.begin(), arr.end(), arr.end()));

	vector<int> answer = arr;
	return answer;
}