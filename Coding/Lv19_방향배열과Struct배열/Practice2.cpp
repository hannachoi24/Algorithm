#include <iostream>
#include <cstring>
using namespace std;

char da[15] = "ABFRCBTRV";
char db[4] = "BTR";

int isSame(int idx)
{
    for (int i = 0; i < 3; i++)
    {
        if (db[i] != da[idx + i])
        {
            return 0;
        }
    }
    return 1;
}

int main()

{
    int len = strlen(da);

    for (int i = 0; i <= len - 3; i++)
    {
        if (isSame(i) == 1)
        {
            cout << "O";
            return 0;
        }
    }
}