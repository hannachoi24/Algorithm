#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int map[10][10];
int path[10];

void dfs(int lev, int now)
{
    if (lev == 2)
    {
        for (int i = 0; i <= lev; i++)
        {
            cout << path[i];
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (map[now][i] == 1)
        {
            path[lev + 1] = i;
            dfs(lev + 1, i);
            path[lev + 1] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    path[0] = 0;

    dfs(0, 0);

    return 0;
}