#include <iostream>
#include <string>
using namespace std;

string name;
int map[10][10];

void dfs(int now)
{
    cout << name[now];

    for (int i = 0; i < name.length(); i++)
    {
        if (map[now][i] == 0)
            continue;

        dfs(i);
    }
}

int main()
{
    cin >> name;

    for (int i = 0; i < name.length(); i++)
    {
        for (int j = 0; j < name.length(); j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0);

    return 0;
}