#include <iostream>
using namespace std;

int arr[8] = {3, 5, 4, 2, 6, 1, 9, 0};

void abc(int idx, int sum)
{
    if (idx == 7)
    {
        cout << "호우 \n";
        return;
    }

    abc(idx + 1, sum + arr[idx + 1]);
    cout << sum << " ";

    int d = 1;
}

int main()
{
    abc(0, arr[0]);

    return 0;
}