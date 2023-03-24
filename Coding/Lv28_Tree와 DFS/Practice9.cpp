#include <iostream>
#include <string>
using namespace std;

// 트리(사이클x)

int main()
{
    string name = "ABTQVX";
    int map[6][6] = {
        0, 1, 1, 1, 0, 0,
        0, 0, 0, 0, 1, 1}; // 안 채워준 나머지는 0으로 초기화

    int n;
    cin >> n;

    for (int i = 0; i < 6; i++)
    {
        if (map[n][i] == 1)
            cout << name[i];
    }

    return 0;
}