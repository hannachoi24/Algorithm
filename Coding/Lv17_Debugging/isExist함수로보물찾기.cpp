#include <iostream>
using namespace std;

int arr[3][3] = {
    3,
    5,
    9,
    4,
    2,
    1,
    5,
    1,
    5,
};

int isExist(int n)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == n)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int num[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> num[i];

        if (isExist(num[i]))
        {
            cout << num[i] << ":존재" << endl;
        }
        else
            cout << num[i] << ":미발견" << endl;
    }

    return 0;
}