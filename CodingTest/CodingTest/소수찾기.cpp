//프로그래머스 코딩테스트 Level2 <소수찾기>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

//소수인가?
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
    set<int>setanswer{};                             //set을 통해 중복없이 오름차순으로 정렬

    sort(numbers.begin(), numbers.end());           //오름차순 정렬

    do
    {
        string tmp;
        for (int i = 0; i < numbers.size(); ++i)
        {
            tmp += numbers[i];
            //stoi()는 문자열을 숫자로 변환해주는 함수(얘를 통해서 012,12의 중복 또한 막기 가능)
            if (isPrime(stoi(tmp)))                
            {
                setanswer.insert(stoi(tmp));
            }
        }
    } 
    while (next_permutation(numbers.begin(), numbers.end()));      
    //next_permutation은 만들 수 있는 모든 순열을 만들어줌(다 만들면 fasle를 리턴)
    //이 함수 사용하기 위해서는 numbers가 오름차순으로 정렬되어 있어야 함

    answer = setanswer.size();

    return answer;
}*/



int solution(string numbers) {
    int answer = 0;
    vector<int> ans;

    sort(numbers.begin(), numbers.end());           //오름차순 정렬

    do
    {
        string tmp;
        for (int i = 0; i < numbers.size(); ++i)
        {
            tmp += numbers[i];
            //stoi()는 문자열을 숫자로 변환해주는 함수(얘를 통해서 012,12의 중복 또한 막기 가능)
            if (isPrime(stoi(tmp)))
            {
                ans.push_back(stoi(tmp));
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    //next_permutation은 만들 수 있는 모든 순열을 만들어줌(다 만들면 fasle를 리턴)
    //이 함수 사용하기 위해서는 numbers가 오름차순으로 정렬되어 있어야 함
    sort(ans.begin(), ans.end()); // unique 사용 전에 정렬
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    answer = ans.size();


    return answer;
}