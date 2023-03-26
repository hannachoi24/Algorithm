#include <iostream>
#include <vector>
#include <string>
using namespace std;

int map[5][5] = {
    0, 0, 0, 0, 1,
    1, 0, 0, 0, 0,
    0, 1, 0, 0, 0,
    0, 1, 0, 0, 0,
    0, 0, 0, 0, 0};

int main()
{
    vector<string> name = {"Amy", "Bob", "Chloe", "Diane", "Edger"};

    int maxCnt = 0;
    int maxIndex = 0;
    for (int i = 0; i < 5; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            if (map[j][i] == 1)
            {
                cnt++;
            }
        }
        if (cnt > maxCnt)
        {
            maxCnt = cnt;
            maxIndex = i;
        }
    }

    cout << name[maxIndex];

    return 0;
}