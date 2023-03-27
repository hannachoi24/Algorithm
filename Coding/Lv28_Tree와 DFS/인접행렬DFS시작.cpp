#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int map[10][10];

void dfs(int now)
{
    cout << now << " ";
    for (int i = 0; i < n; i++)
    {
        if (map[now][i] == 0)
            continue;
        dfs(i);
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

    dfs(0);

    return 0;
}