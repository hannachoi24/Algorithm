#include <iostream>
using namespace std;

int main()
{
    int map[3][6] = {
        3,
        5,
        4,
        2,
        2,
        3,
        1,
        3,
        3,
        3,
        4,
        2,
        5,
        4,
        4,
        2,
        3,
        5,
    };

    char price[6] = "TPGKC";

    char r; // 행
    int c;  // 열

    cin >> r >> c;

    cout << price[map[r - 'A'][c - 1] - 1];

    return 0;
}