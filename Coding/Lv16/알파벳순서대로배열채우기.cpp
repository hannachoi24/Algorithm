#include <iostream>
using namespace std;

char arr[6][3] = {
    'R', 'L', 'F',
    'Q', 'K', 'E',
    'P', 'J', 'D',
    'O', 'I', 'C',
    'N', 'H', 'B',
    'M', 'G', 'A'};

int main()
{

    int x, y;
    cin >> x >> y;
    cout << arr[x][y];
    return 0;
}