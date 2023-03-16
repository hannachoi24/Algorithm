#include <iostream>
using namespace std;

// 중복 순열
// 6개의 알파벳중 중복 없이 4개의 알페벳을 만들어라

char word[7] = "ERATKZ";
char path[10];
bool visit[6];

void run(int lev)
{
    if (lev == 4)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 6; i++)
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
    run(0);

    return 0;
}