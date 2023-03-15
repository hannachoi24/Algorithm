#include <iostream>
using namespace std;

// Level2에 도달했을 때마다, path를 모두 출력 해주세요.

char word[4] = "ABC";
char path[10];

void run(int lev)
{
    if (lev == 2)
    {
        for (int i = 0; i < lev; i++)
        {
            cout << path[i];
        }
        cout << '\n';

        return;
    }

    for (int i = 0; i < 3; i++)
    {
        path[lev] = word[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    run(0);

    return 0;
}