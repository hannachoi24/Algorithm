#include <iostream>
using namespace std;

// 배열의 각 행에서 숫자 하나씩 선택한 후 모두 더한 값 출력

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

void print(int lev, int sum)
{
    for (int i = 0; i < lev; i++)
    {
        cout << path[i] << " ";
    }
    cout << "= " << sum;
    cout << '\n';
}

void run(int lev, int sum)
{
    if (lev == 3)
    {
        print(lev, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = map[lev][i];         // 현재 선택한것에 i에 해당하는 값
        run(lev + 1, sum + map[lev][i]); // sum += 과 sum의 차이 -> 전자는 sum값을 바꿈, 후자는 sum값을 바꾸지 않음
        path[lev] = 0;
    }
}

int main()
{
    run(0, 0);

    return 0;
}
