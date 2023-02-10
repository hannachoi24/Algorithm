#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char vect[10] = "MINCODING";
    int n;
    char tar[10];
    cin >> n;

    int dat[200] = {0};

    for (int i = 0; i < n; i++)
    {

        cin >> tar[i];
    }

    int len = strlen(vect);
    for (int i = 0; i < len; i++)
    {
        dat[vect[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (dat[tar[i]] == 1)
        {
            cout << "O";
        }
        else
            cout << "X";
    }

    return 0;
}