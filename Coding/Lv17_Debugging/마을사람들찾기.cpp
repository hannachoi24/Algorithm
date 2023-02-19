#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char vect[7] = "BTKIGZ";
    char target[5];

    for (int i = 0; i < 4; i++)
    {
        cin >> target[i];
    }

    int len = strlen(vect);
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (vect[i] == target[j])
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}