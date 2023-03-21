#include <iostream>
using namespace std;

int main()
{
    int mask[2][5] = {
        0, 0, 1, 0, 0,
        0, 0, 1, 1, 1};
    int arr[2][5] = {
        3, 5, 4, 1, 1,
        3, 5, 2, 5, 6};

    int num;
    cin >> num;

    bool exist = false;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mask[i][j] && arr[i][j] == num)
            {
                exist = true;
                break;
            }
        }
    }

    if (exist)
    {
        cout << num << " 존재\n";
    }
    else
    {
        cout << num << " 없음\n";
    }

    return 0;
}
