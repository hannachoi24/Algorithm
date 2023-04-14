#include <iostream>
using namespace std;

/* 금, 은, 동 출력
메모리제한 40Byte
최대 N = 20
*/

int main()
{
    freopen_s(new FILE *, "input.txt", "r", stdin);

    int n;
    cin >> n;

    double result[4] = {0};

    for (int i = 0; i < n; i++)
    {
        int pos = i;
        if (i >= 3)
        {
            pos = 3;
        }

        cin >> result[pos];

        for (int j = pos; j > 0; j--)
        {
            if (result[j] > result[j - 1])
            {
                swap(result[j - 1], result[j]);
            }
            else
                break;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%.1lf\n", result[i]);
        // cout << result[i] << '\n';
    }

    return 0;
}