#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> alist(7);

queue<int> q;

int main()
{
    alist[5] = {3, 1};
    alist[3] = {2};
    alist[1] = {4};
    alist[4] = {0, 6};

    q.push(5);

    while (!q.empty())
    {
        // 1. 큐에서 뺀다(탐색)
        int now = q.front();
        q.pop();
        cout << now << " ";

        // 2. 다음 갈 곳 예약걸기(큐 등록)
        for (int i = 0; i < alist[now].size(); i++)
        {
            int next = alist[now][i];
            q.push(next);
        }
    }

    return 0;
}