#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1; // 며칠만에 개발 되는지 계산

        if (answer.empty() || max_day < day)
        {
            answer.push_back(1);
            max_day = day;
        }
        else
            answer.back()++;
    }

    return answer;
}

int main()
{
    // vector<int> progresses{93, 30, 55};
    // vector<int> speeds{1, 30, 5};

    vector<int> progresses{95, 90, 99, 99, 80, 99};
    vector<int> speeds{1, 1, 1, 1, 1, 1};

    vector<int> sol = solution(progresses, speeds);
    int size = sol.size();

    for (int i = 0; i < size; i++)
    {
        cout << sol[i] << ' ';
    }

    cout << '\n';

    return 0;
}