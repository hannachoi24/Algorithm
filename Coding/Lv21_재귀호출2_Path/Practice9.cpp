#include <iostream>
using namespace std;

void run(int lev)
{
    if (lev == 2)
    {
        // cout << "#"; # 4개 출력
        return;
    }

    // cout << "#"; # 3개 출력

    for (int i = 0; i < 2; i++)
    {
        cout << i; // 가기전 출력
        run(lev + 1);
        cout << i; // 돌아와서 출력
    }

    int d = 1;
}

int main()
{
    run(0);

    return 0;
}