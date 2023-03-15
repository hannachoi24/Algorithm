#include <iostream>
using namespace std;

int arr[4] = {4, 5, 9, -6};
int flag;

void run(int lev, int sum)
{
    if (lev == 3)
    {
        if (sum == 12)
        {
            flag = 1;
        }

        // cout << sum << " ";
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        run(lev + 1, sum + arr[i]);
        if (flag)
            return; // 이 코드 넣어주면 발견하자마자 꺼지기 때문에 속도가 빨라짐
    }
}

int main()
{
    run(0, 0);

    if (flag)
        cout << "있다";
    else
        cout << "없다";

    return 0;
}