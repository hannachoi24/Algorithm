#include <iostream>
using namespace std;

// 자리수 입력 받고 만들 수 있는 단어 구현

int map[3][4] = {
    4,
    5,
    1,
    9,
    9,
    5,
    3,
    3,
    4,
    4,
    5,
    6,
};

int path[3];

void print(int lev)
{
    int sum = 0;
    for (int i = 0; i < lev; i++)
    {
        sum += path[i];
        cout << path[i] << " ";
    }
    cout << "= " << sum;
    cout << '\n';
}

void run(int lev)
{
    if (lev == 3)
    {
        print(lev);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = map[lev][i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    run(0);

    return 0;
}
