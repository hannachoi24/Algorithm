#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 1; // 자기 자신 포함해서 시작
    for (int i = 1; i < n; i++)
    {
        int sum = i;
        for (int j = i + 1; j < n; j++)
        {
            sum += j;
            if (sum == n)
                answer++;
            else if (sum > n)
                break;
        }
    }

    return answer;
}