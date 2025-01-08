//프로그래머스 <최소직사각형> 코딩테스트
#include <string>
#include <vector>

using namespace std;

//if문을 통해 가로 세로 값을 비교해 큰 값을 가로로 보내 거기서 가장 큰 값, 세로에서 가장 큰 값을 찾아 곱해
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int h = 0;
    int w = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            //만약 가로의 길이보다 세로의 길이가 더 크다면 swap()을 사용해 바꾸기
            swap(sizes[i][1], sizes[i][0]);
        }
        //w, h 값을 max()를 통해 반복문이 실행되는 동안 계속 큰 값을 갱신
        w = max(w, sizes[i][0]);
        h = max(h, sizes[i][1]);
    }
    answer = w * h;

    return answer;
}