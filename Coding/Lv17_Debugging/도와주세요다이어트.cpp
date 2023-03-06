#include <iostream>
using namespace std;

int levTable[4][2] = {
    10, 20,
    30, 60,
    100, 150,
    200, 300};

int kal[6];

int cnt1;
int cnt2;
int cnt3;
int cnt4;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> kal[i];
    }

    for (int i = 0; i < 6; i++)
    {
        if (levTable[0][0] <= kal[i] && kal[i] <= levTable[0][1])
        {
            cnt1++;
        }

        else if (levTable[1][0] <= kal[i] && kal[i] <= levTable[1][1])
        {
            cnt2++;
        }

        else if (levTable[2][0] <= kal[i] && kal[i] <= levTable[2][1])
        {
            cnt3++;
        }

        else if (levTable[3][0] <= kal[i] && kal[i] <= levTable[3][1])
        {
            cnt4++;
        }
    }

    cout << "lev0:" << cnt1 << '\n';
    cout << "lev1:" << cnt2 << '\n';
    cout << "lev2:" << cnt3 << '\n';
    cout << "lev3:" << cnt4 << '\n';

    return 0;
}