#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char arr[10];
    int dat[200] = {0};

    cin >> arr;
    int len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        dat[arr[i]]++;
    }

    for (int i = 0; i < 200; i++)
    {
        if (dat[i] == 0)
            continue;

        cout << char(i) << ":" << dat[i] << endl;
    }

    return 0;
}