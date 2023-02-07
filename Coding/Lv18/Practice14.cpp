#include <iostream>
#include <cstring>
using namespace std;

// Direct Address Datatable

int main()
{
    char buf[10] = "ABAAASAQ";
    int len = strlen(buf);

    int dat[200] = {0};

    for (int i = 0; i < len; i++)
    {
        dat[buf[i]]++;
    }

    for (int i = 0; i < 200; i++)
    {
        if (dat[i] == 0)
            continue;

        cout << (char)i << " : " << dat[i] << endl;
    }

    return 0;
}