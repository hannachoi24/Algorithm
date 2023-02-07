#include <iostream>
using namespace std;

// Direct Address Datatable

int main()
{
    int vec[5] = {4, 4, 2, 4, 4};

    int dat[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        dat[vec[i]]++;
    }

    for (int i = 0; i < 5; i++)
    {
        if (dat[i] > 0)
        {
            cout << i << " : " << dat[i] << endl;
        }
    }
    return 0;
}