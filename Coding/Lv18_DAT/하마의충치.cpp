#include <iostream>
using namespace std;

int main()
{
    int up[5];
    int down[5];

    int cnt = 0;

    for (int k = 0; k < 5; k++)
    {
        cin >> up[k];
    }

    for (int k = 0; k < 5; k++)
    {
        cin >> down[k];
    }

    for (int k = 0; k < 5; k++)
    {
        if (up[k] == 1 && down[k] == 1)
        {
            cnt++;
        }
    }

    cout << cnt << "개";

    return 0;
}