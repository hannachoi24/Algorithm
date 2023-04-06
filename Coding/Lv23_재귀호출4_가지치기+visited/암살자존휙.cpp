#include <iostream>
using namespace std;

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }

    bool isDanger = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (x[i] == x[j] || y[i] == y[j]) // 같은 행 또는 같은 열에 위치한 경우
            {
                isDanger = true;
                break;
            }
        }
        if (isDanger)
        {
            break;
        }
    }

    if (isDanger)
    {
        cout << "위험" << '\n';
    }
    else
        cout << "안전" << '\n';

    return 0;
}