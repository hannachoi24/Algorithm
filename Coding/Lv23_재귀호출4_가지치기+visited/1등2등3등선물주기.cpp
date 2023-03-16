#include <iostream>
using namespace std;

char name[5];
char path[10];
bool visit[4];

void run(int lev)
{
    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (visit[i] == true)
            continue;
        visit[i] = true;
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
        visit[i] = false;
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> name[i];
    }

    run(0);

    return 0;
}