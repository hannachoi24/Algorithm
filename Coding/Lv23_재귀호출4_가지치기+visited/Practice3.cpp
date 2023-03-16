#include <iostream>
using namespace std;

// sum이 10보다 작은 것만 출력

char path[10];

void run(int lev, int sum)
{
    // if (sum > 10) return; // 가지치기1 (밑으로 안 내려가도록)

    if (lev == 3)
    {
        for (int i = 0; i < lev; i++)
        {
            cout << path[i] << " ";
        }
        cout << "= " << sum;
        cout << '\n';

        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        if (sum + i > 10) // 가지치기2
            continue;
        path[lev] = '0' + i;
        run(lev + 1, sum + i);
        path[lev] = 0;
    }
}

int main()
{
    run(0, 0);

    return 0;
}
