#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int by = brown + yellow;

    for (int h = 3; h <= (by / 2) ; h++)
    {
        if ((by % h) == 0)
        {
            int w = by / h;

            if ((w - 2) * (h - 2) == yellow)
            {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    return answer;
}