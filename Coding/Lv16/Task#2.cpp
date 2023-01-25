#include <iostream>

using namespace std;

char arr[4][4] = {'A', 'B', 'K', 'T',
                  'K', 'F', 'C', 'F',
                  'B', 'B', 'Q', 'Q',
                  'T', 'P', 'Z', 'F'};

int main()
{

    char a, b;
    int cnt = 0;
    cin >> a >> b;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == a || arr[i][j] == b)
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
