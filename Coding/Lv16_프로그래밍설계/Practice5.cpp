#include <iostream>

using namespace std;

/* 누적 값을 구하시오 */

int da[5] = {1, 15, 7, 9, -7};
int db[5] = {0};

int main()
{
    db[0] = da[0];

    // 1~4까지 누적
    for (int i = 1; i < 5; i++)
    {
        db[i] = da[i] + db[i - 1];
    }

    // 출력
    for (int i = 0; i < 5; i++)
    {
        cout << db[i] << endl;
    }

    return 0;
}