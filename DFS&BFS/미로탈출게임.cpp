#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
vector<string> data;
vector<vector<int>> v(51, vector<int>(51, 0));

void BFS()
{
    pair<int, int> start = {0, 0};
    queue<pair<int, int>> q;
    q.push(start);
    v[0][0] = 1;

    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())

    {
        pair<int, int> cur = q.front();
        int curX = cur.first;
        int curY = cur.second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + delta[i][0];
            int ny = curY + delta[i][1];

            if (!(0 <= nx && nx < n && 0 <= ny && ny < n))
                continue;

            if (data[nx][ny] != '1')
                continue;

            if (v[nx][ny] == 0)
            {
                v[nx][ny] = v[curX][curY] + 1;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
    return;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        data.push_back(s);
    }

    BFS();

    cout << v[n - 1][n - 1];
    cout << "\n";

    return 0;
}
