#include <iostream>
#include <string>
using namespace std;

char arr[4][4] = {
    "153",
    "455",
    "335",
    "462"};

char a, b;

int main()
{
    cin >> a >> b;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] >= a && arr[i][j] <= b)
            {
                arr[i][j] = '0';
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == '0')
            {
                arr[i][j] = '#';
            }
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int main()
{
    int vect[4][3] =
    {
        1, 5, 3,
        4, 5, 5,
        3, 3, 5,
        4, 6, 2,
    };

    int a, b;
    cin >> a >> b;

    int x, y;
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 3; x++)
        {
            if (a <= vect[y][x] && vect[y][x] <= b)
            {
                vect[y][x] = 0;
            }
        }
    }

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 3; x++)
        {
            if (vect[y][x] == 0) printf("# ");
            else printf("%d ", vect[y][x]);
        }
        printf("\n");
    }

    return 0;
}
*/