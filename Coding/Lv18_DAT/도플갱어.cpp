#include <iostream>
using namespace std;

int main()
{
    int arr[6];
    int dat[200] = {0};

    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
        dat[arr[i]]++;
    }

    for (int k = 0; k < 6; k++)
    {
        if (dat[arr[k]] > 1)
        {
            cout << "도플갱어 발견";
            return 0;
        }
    }

    cout << "미발견";

    return 0;
}