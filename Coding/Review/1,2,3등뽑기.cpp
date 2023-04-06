#include <iostream>
using namespace std;

int n;
int cnt = 0;
bool visited[10] = {false};

void backtrack(int lev)
{
    if (lev == 3)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true)
            continue;
        visited[i] = true;
        backtrack(lev + 1);
        visited[i] = false;
    }
}

int main()
{
    cin >> n;

    backtrack(0);

    cout << cnt;

    return 0;
}