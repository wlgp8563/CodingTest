//프로그래머스 <과일 장수> Level1 c++ 
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());  //내림차순 정렬(큰 수부터 작은 수로 정렬)

    //m개 중 가장 작은 숫자로 계산, 근데 배열 시작은 0부터라서 -1해줌, 그리고 배열 크기만 큼 반복, 근데 i는 갯수단위만큼 커짐
    for (int i = m -1; i < score.size(); i += m)
    {
        answer += score[i] * m;
    }
    return answer;
}

//우선순위큐를 활용(얘로 하면 push 사용해 넣으면 큰 수로 순서대로 정렬되어 큐에 들어감)
priority_queue <int> pq;
int solution(int k, int m, vector<int> score) {
    int answer = 0;

    //score 크기만큼 우선순위 큐 pq에 넣음
    for (int i = 0; i < score.size(); i++)
    {
        pq.push(score[i]);
    }
    //우선순위큐 pq의 크기가 m보다 작기 전까지 반복
    while (pq.size() >= m)
    {
        //0부터 m-2 index까지는 pop을 통해 큐에서 삭제 
        for (int i = 0; i < m - 1; i++)
        {
            pq.pop();
        }
        //m-1번 index가 결국 m개째니까 그 값을 가져와서 곱해서 계속 더한 값이 answer
        answer += pq.top() * m;
        //또 반복 전에 m-1 index값 pop으로 삭제
        pq.pop();
    }
    return answer;
}

/*
주어질 수 있는 사과 총 갯수 7 <= score_len <= 1,000,000
1~k 점수(조건 3 <= k <= 9)
k가 최고점이라는 뜻
m개씩 사과 포장(조건 3 <= m <= 10)
가격 가장 낮은 사과 점수 기준 = p * m
최대 이익 = answer
*/