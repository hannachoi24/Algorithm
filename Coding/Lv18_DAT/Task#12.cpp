#include <iostream>
using namespace std;

int main()
{
    char arr[10] = "";

    cin >> arr;

    int dat[200] = {0};

    for (int i = 0; i < 10; i++)
    {
        dat[arr[i]]++;
    }

    int max = 0;
    for (int k = 0; k < 200; k++)
    {
        if (dat[k] > dat[max])
        {
            max = k;
        }
    }

    cout << (char)max;

    return 0;
}