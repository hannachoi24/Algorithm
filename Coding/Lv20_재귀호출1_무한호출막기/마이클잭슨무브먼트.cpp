#include <iostream>
using namespace std;

int arr[6];

void run(int idx)
{

    cout << arr[idx] << " ";
    if (idx == 5)
    {
        return;
    }

    run(idx + 1);
    cout << arr[idx] << " ";
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    run(0);

    return 0;
}