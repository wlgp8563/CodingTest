//���α׷��ӽ� �ڵ��׽�Ʈ Level2 <�Ҽ�ã��>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

//�Ҽ��ΰ�?
bool isPrime(int n)
{
    if (n == 0 || n == 1) return false;

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

/*int solution(string numbers) {
    int answer = 0;
    set<int>setanswer{};                             //set�� ���� �ߺ����� ������������ ����

    sort(numbers.begin(), numbers.end());           //�������� ����

    do
    {
        string tmp;
        for (int i = 0; i < numbers.size(); ++i)
        {
            tmp += numbers[i];
            //stoi()�� ���ڿ��� ���ڷ� ��ȯ���ִ� �Լ�(�긦 ���ؼ� 012,12�� �ߺ� ���� ���� ����)
            if (isPrime(stoi(tmp)))                
            {
                setanswer.insert(stoi(tmp));
            }
        }
    } 
    while (next_permutation(numbers.begin(), numbers.end()));      
    //next_permutation�� ���� �� �ִ� ��� ������ �������(�� ����� fasle�� ����)
    //�� �Լ� ����ϱ� ���ؼ��� numbers�� ������������ ���ĵǾ� �־�� ��

    answer = setanswer.size();

    return answer;
}*/



int solution(string numbers) {
    int answer = 0;
    vector<int> ans;

    sort(numbers.begin(), numbers.end());           //�������� ����

    do
    {
        string tmp;
        for (int i = 0; i < numbers.size(); ++i)
        {
            tmp += numbers[i];
            //stoi()�� ���ڿ��� ���ڷ� ��ȯ���ִ� �Լ�(�긦 ���ؼ� 012,12�� �ߺ� ���� ���� ����)
            if (isPrime(stoi(tmp)))
            {
                ans.push_back(stoi(tmp));
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    //next_permutation�� ���� �� �ִ� ��� ������ �������(�� ����� fasle�� ����)
    //�� �Լ� ����ϱ� ���ؼ��� numbers�� ������������ ���ĵǾ� �־�� ��
    sort(ans.begin(), ans.end()); // unique ��� ���� ����
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    answer = ans.size();


    return answer;
}