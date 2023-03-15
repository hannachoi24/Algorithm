#include <iostream>
using namespace std;

// 배열의 각 행에서 숫자 하나씩 선택한 후 모두 곱하고 결과 값 중에서 가장 큰 값 출력

int map[4][3] = {
    1,
    3,
    -5,
    -8,
    3,
    4,
    -2,
    -5,
    -9,
    5,
    5,
    4,
};

int maxi = -999999999;

void run(int lev, int mul)
{
    if (lev == 4)
    {
        if (mul > maxi)
            maxi = mul;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        run(lev + 1, mul * map[lev][i]); // sum += 과 sum의 차이 -> 전자는 sum값을 바꿈, 후자는 sum값을 바꾸지 않음
    }
}

int main()
{
    run(0, 1);

    cout << maxi;

    return 0;
}
