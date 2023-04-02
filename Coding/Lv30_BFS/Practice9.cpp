#include <iostream>
#include <queue>
using namespace std;

// a->b 까지 최소 이동 수

struct Node
{
    int n;
    int lev;
};

vector<vector<int>> alist(5);
queue<Node> q;

bool visited[10] = {false};

int a, b;

int main()
{
    cin >> a >> b;

    alist[0] = {1, 4};
    alist[1] = {3, 4};
    alist[2] = {0};
    alist[3] = {2};

    q.push({a, 0});
    visited[0] = true;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        // if (now.n == b)
        // {
        //     cout << now.lev;
        //     break;
        // }

        for (int i = 0; i < alist[now.n].size(); i++)
        {
            int next = alist[now.n][i];

            if (visited[next] == true)
                continue;
            visited[next] = true;

            q.push({next, now.lev + 1});

            // 더 빨리 최소 경로 찾는 코드(등록 할 때)
            if (next == b)
            {
                cout << now.lev + 1;
                return 0;
            }
        }
    }

    return 0;
}