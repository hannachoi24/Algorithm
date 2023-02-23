#include <iostream>
using namespace std;

/* for문 연습*/

int main()
{

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                cout << i << " " << j << " " << k << '\n';
            }
        }
    }

    return 0;
}