#include <iostream>
using namespace std;

// 출력: 3542619호우9162453

int arr[7] = {3, 5, 4, 2, 6, 1, 9};

void abc(int idx)
{
    if (idx == 7)
    {
        cout << "호우 \n";
        return;
    }

    cout << arr[idx];
    abc(idx + 1);
    cout << arr[idx];

    int d = 1;
}

int main()
{
    abc(0);

    return 0;
}