#include <iostream>
using namespace std;

int main()
{
    int vect[3][2][2] = {
        {{2, 4}, {1, 5}},
        {{2, 3}, {3, 6}},
        {{7, 3}, {1, 5}},
    };

    int input;
    int max = -99;
    int min = 99;

    cin >> input;

    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            if (vect[input][j][k] > max)
                max = vect[input][j][k];
            if (vect[input][j][k] < min)
                min = vect[input][j][k];
        }
    }

    cout << "MAX=" << max << '\n';
    cout << "MIN=" << min << '\n';

    return 0;
}