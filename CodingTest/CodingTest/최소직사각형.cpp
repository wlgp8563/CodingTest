//���α׷��ӽ� <�ּ����簢��> �ڵ��׽�Ʈ
#include <string>
#include <vector>

using namespace std;

//if���� ���� ���� ���� ���� ���� ū ���� ���η� ���� �ű⼭ ���� ū ��, ���ο��� ���� ū ���� ã�� ����
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int h = 0;
    int w = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            //���� ������ ���̺��� ������ ���̰� �� ũ�ٸ� swap()�� ����� �ٲٱ�
            swap(sizes[i][1], sizes[i][0]);
        }
        //w, h ���� max()�� ���� �ݺ����� ����Ǵ� ���� ��� ū ���� ����
        w = max(w, sizes[i][0]);
        h = max(h, sizes[i][1]);
    }
    answer = w * h;

    return answer;
}