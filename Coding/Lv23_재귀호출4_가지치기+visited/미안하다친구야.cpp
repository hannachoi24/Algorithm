#include <iostream>
using namespace std;

string word = "EWABC";
char path[10];
bool visit[5];
char a;

void run(int lev)
{
    if (path[lev - 1] == a)
        return;

    if (lev == 4)
    {
        cout << path << '\n';
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
    cin >> a;

    run(0);

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <string>
using namespace std;

string name = "EWABC";

int via[10];
char path[10];

void run(int level)
{
    if (level == 4) {
        cout << path << endl;
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (via[i] == 0) {
            via[i] = 1;
            path[level] = name[i];
            run(level + 1);
            path[level] = 0;
            via[i] = 0;
        }
    }
}

int main()
{
    char except;
    cin >> except;

    //제외시킬 친구를 via에 미리 체크
    for (int i = 0; i < 5; i++) {
        if (name[i] == except) {
            via[i] = 1;
        }
    }

    run(0);

    return 0;
}
*/