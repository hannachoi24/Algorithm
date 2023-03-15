#include <iostream>
#include <cstring>
using namespace std;

char tar[4];

char name[10] = "ABCD";
char path[10];
int cnt;

int exitFlag;

int isSame()
{
    for (int i = 0; i < 3; i++)
    {
        if (tar[i] != path[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void run(int level)
{
    if (exitFlag == 1)
        return;

    if (level == 3)
    {
        cnt++;
        if (isSame() == 1)
        {
            cout << cnt << "번째";
            exitFlag = 1;
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[level + 1] = name[i];
        run(level + 1);
        path[level + 1] = 0;
    }
}

int main()
{
    cin >> tar;

    run(0);
}

/* 또 다른 코드
#include <iostream>
#include <string>
using namespace std;

char word[5] = "ABCD";
char path[10];
string tar; // "AAD"
int cnt;
bool isExit;

void run(int lev)
{
    if (lev == 3)
    {
        bool flag = false;
        for (int i = 0; i < tar.length(); i++)
        {
            if (path[i] != tar[i])
            {
                flag = true;
                break;
            }
        }
        cnt++; // 틀린게 있든 맞는게 있든 어차피 cnt는 증가하니까 for루프 밖에다

        // path == tar
        if (!flag)
        {
            isExit = true;
            cout << cnt << "번째";
            return;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = word[i];
        run(lev + 1);
        if (isExit)
            return;
        path[lev] = 0;
    }
}

int main()
{
    cin >> tar;
    isExit = false;

    run(0);

    return 0;
}
*/