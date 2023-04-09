#include <iostream>
using namespace std;

int map[3][4] = {
    3, 5, 4, 1,
    1, 1, 2, 3,
    6, 7, 1, 2};

int nums[4];

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j] == nums[0])
            {
                map[i][j] = nums[1];
            }
            else if (map[i][j] == nums[1])
            {
                map[i][j] = nums[2];
            }
            else if (map[i][j] == nums[2])
            {
                map[i][j] = nums[3];
            }
            else if (map[i][j] == nums[3])
            {
                map[i][j] = nums[0];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}