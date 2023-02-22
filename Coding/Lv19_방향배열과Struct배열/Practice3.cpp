#include <iostream>
using namespace std;

int arr[9] = {4, 1, 2, 3, 4, 1, 2, 3, 3};
int tar[3] = {1, 2, 3};

int isSame(int idx)
{
    for (int i = 0; i < 3; i++)
    {
        if (tar[i] != arr[idx + i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int cnt = 0;
    for (int i = 0; i <= 9 - 3; i++)
    {
        if (isSame(i))
        {
            cnt++;
        }

        // cnt += isSame(i);
    }

    cout << cnt;

    return 0;
}