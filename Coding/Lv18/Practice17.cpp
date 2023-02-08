#include <iostream>
#include <cstring>
using namespace std;

// Direct Address Datatable

int main()
{
    char arr[10] = "BBQBHSBTS";
    int len = strlen(arr);

    int dat[200] = {0};

    for (int i = 0; i < len; i++)
    {
        dat[arr[i]]++;
    }

    // int max = 0;
    // int maxIndex;
    // for (int i = 0; i < 200; i++) {
    //     if(dat[i] > max) {
    //         max = dat[i];
    //         maxIndex = i;
    //     }
    // }

    int maxIndex = 0;

    for (int i = 0; i < 200; i++)
    {
        if (dat[i] > dat[maxIndex])
        {
            maxIndex = i;
        }
    }

    cout << (char)maxIndex;

    return 0;
}