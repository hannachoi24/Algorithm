#include <iostream>
using namespace std;

int map[10][10];
char path[10];

void dfs(int lev, int now)
{
    int flag = 0;

    for (int i = 0; i < 10; i++)
    {
        if (map[now][i] == 1)
        {
            flag = 1;
            path[lev + 1] = 'A' + i;
            dfs(lev + 1, i);
            path[lev + 1] = 0;
        }
    }

    if (flag == 0)
    {
        cout << path << '\n';
    }
}

int main()
{
    path[0] = 'A';

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 0);

    return 0;
}