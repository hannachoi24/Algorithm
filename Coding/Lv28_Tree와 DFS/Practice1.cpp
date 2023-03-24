#include <iostream>
#include <string>
using namespace std;

// 인접 행렬

string name = "BTAR";

int map[4][4] = {
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 0, 0,
    1, 1, 0, 0};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 4; i++)
    {
        if (map[n][i] == 1)
        {
            cout << name[i];
        }
    }

    return 0;
}