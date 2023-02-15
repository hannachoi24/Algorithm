#include <iostream>
using namespace std;

int arr[2][3];

void getMax()
{
    int max = 0;
    int tempX, tempY;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                tempX = i;
                tempY = j;
            }
        }
    }
    cout << "(" << tempX << "," << tempY << ")" << '\n';
}

void getMin()
{
    int min = 21e8;
    int tempX, tempY;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                tempX = i;
                tempY = j;
            }
        }
    }

    cout << "(" << tempX << "," << tempY << ")";
}

int main()
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    getMax();
    getMin();

    return 0;
}