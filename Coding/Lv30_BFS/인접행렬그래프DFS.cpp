#include <iostream>
using namespace std;

int map[6][6] = {
    0, 0, 1, 1, 0, 1,
    0, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0};

int start;
bool visited[10] = {false};

void dfs(int now)
{
    cout << now << " ";

    for (int i = 0; i < 6; i++)
    {
        if (map[now][i] == 0)
            continue;
        if (visited[i] == true)
            continue;
        visited[i] = true;
        dfs(i);
    }
}

int main()
{
    cin >> start;
    visited[start] = true;
    dfs(start);
    return 0;
}