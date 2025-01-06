//���α׷��ӽ� <���� ���> Level1 c++ 
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());  //�������� ����(ū ������ ���� ���� ����)

    //m�� �� ���� ���� ���ڷ� ���, �ٵ� �迭 ������ 0���Ͷ� -1����, �׸��� �迭 ũ�⸸ ŭ �ݺ�, �ٵ� i�� ����������ŭ Ŀ��
    for (int i = m -1; i < score.size(); i += m)
    {
        answer += score[i] * m;
    }
    return answer;
}

//�켱����ť�� Ȱ��(��� �ϸ� push ����� ������ ū ���� ������� ���ĵǾ� ť�� ��)
priority_queue <int> pq;
int solution(int k, int m, vector<int> score) {
    int answer = 0;

    //score ũ�⸸ŭ �켱���� ť pq�� ����
    for (int i = 0; i < score.size(); i++)
    {
        pq.push(score[i]);
    }
    //�켱����ť pq�� ũ�Ⱑ m���� �۱� ������ �ݺ�
    while (pq.size() >= m)
    {
        //0���� m-2 index������ pop�� ���� ť���� ���� 
        for (int i = 0; i < m - 1; i++)
        {
            pq.pop();
        }
        //m-1�� index�� �ᱹ m��°�ϱ� �� ���� �����ͼ� ���ؼ� ��� ���� ���� answer
        answer += pq.top() * m;
        //�� �ݺ� ���� m-1 index�� pop���� ����
        pq.pop();
    }
    return answer;
}

/*
�־��� �� �ִ� ��� �� ���� 7 <= score_len <= 1,000,000
1~k ����(���� 3 <= k <= 9)
k�� �ְ����̶�� ��
m���� ��� ����(���� 3 <= m <= 10)
���� ���� ���� ��� ���� ���� = p * m
�ִ� ���� = answer
*/