#include <iostream>
using namespace std;

int arr[8] = {3, 7, 4, 1, 9, 4, 6, 2};

void run(int level)
{
    cout << arr[level] << " ";
    if (level == 0)
    {
        return;
    }

    run(level - 1);
    cout << arr[level] << " ";
}

int main()
{
    int idx;
    cin >> idx;

    run(idx);

    return 0;
}