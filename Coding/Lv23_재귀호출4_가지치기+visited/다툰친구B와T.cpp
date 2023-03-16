#include <iostream>
#include <string>
using namespace std;

char word[27];
char path[10];
int cnt;

void run(int lev)
{
    if (lev == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (path[i] == 'B' && path[i + 1] == 'T' || path[i] == 'T' && path[i + 1] == 'B')
                return;
        }
        cnt++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = word[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    cin >> word;

    run(0);

    cout << cnt;

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <string>
using namespace std;

string name;
char path[10];
int cnt;

void run(int level)
{
    if (level >= 2 && path[level - 1] == 'B' && path[level - 2] == 'T') return;
    if (level >= 2 && path[level - 1] == 'T' && path[level - 2] == 'B') return;

    if (level == 4)
    {
        cnt++;
        return;
    }

    for (int x = 0; x < 4; x++)
    {
        path[level] = name[x];
        run(level + 1);
        path[level] = 0;
    }
}

int main()
{
    cin >> name;
    run(0);
    cout << cnt;

    return 0;
}
*/