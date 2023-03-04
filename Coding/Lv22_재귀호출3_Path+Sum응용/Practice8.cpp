#include <iostream>
#include <cstring>
using namespace std;

// 자리수 입력 받고 만들 수 있는 단어 구현

int n;
int len;
char name[10] = "ABCD";
char path[10];

void run(int lev, int n)
{
    if (lev == n)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < len; i++)
    {
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    cin >> n;

    len = strlen(name);

    run(0);

    return 0;
}
