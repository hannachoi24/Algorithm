#include <iostream>
using namespace std;

int main()
{
    char alpha[5][3] = {
        {'A', 'B', 'C'},
        {'A', 'G', 'H'},
        {'H', 'I', 'J'},
        {'K', 'A', 'B'},
        {'A', 'B', 'C'}};

    int dat[200] = {0};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dat[alpha[i][j] - 0]++;
        }
    }

    for (int k = 65; k <= 90; k++)
    {
        for (int i = 0; i < dat[k]; i++)
        {
            cout << (char)k;
        }
    }

    return 0;
}