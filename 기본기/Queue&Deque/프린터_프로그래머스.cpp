#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        // 큐에 들어온 순서와 중요도를 넣음
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty())
    {
        int idx = q.front().first;
        int weight = q.front().second;
        q.pop();

        // 우선순위 1순위와 현재값이 같다면
        if (weight == pq.top())
        {
            // 우선순위큐 pop
            pq.pop();
            // 하나가 나갔으므로 카운트
            answer += 1;
            // 현재 나간것이 원하는것과 같다면
            if (idx == location)
            {
                break;
            }
        }
        // 우선순위 1순위와 현재값이 같지않다면 큐 뒤에 넣기
        else
            q.push(make_pair(idx, weight));
    }

    return answer;
}

int main()
{
    vector<int> priorities{2, 1, 3, 2};
    int location = 2;

    int sol = solution(priorities, location);

    cout << sol;
}