#include <iostream>
using namespace std;

int n, x, y;
string input;

int main()
{
    y = 5;
    x = 5;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        if (input == "up")
        {
            y--;
        }
        else if (input == "down")
        {
            y++;
        }
        else if (input == "right")
        {
            x++;
        }
        else if (input == "left")
        {
            x--;
        }
        else if (input == "click")
        {
            cout << y << "," << x << '\n';
        }
    }

    return 0;
}