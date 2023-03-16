#include <iostream>
using namespace std;

char word[6] = "BTSKR";
char path[10];
bool visit[5];
int n;
int cnt;

void run(int lev)
{
    if (lev == n)
    {
        if (visit[2] == true)
            cnt++;
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (visit[i] == true)
            continue;
        visit[i] = true;
        path[lev] = word[i];
        run(lev + 1);
        path[lev] = 0;
        visit[i] = false;
    }
}

int main()
{
    cin >> n;

    run(0);

    cout << cnt;

    return 0;
}