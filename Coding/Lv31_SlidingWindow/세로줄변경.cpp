#include <iostream>
#include <string>
using namespace std;

string map[5];

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> map[i];
    }

    for (int i = 0; i < 5; i++)
    {
        swap(map[i][1], map[i][3]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (map[i] == "MAPOM")
        {
            cout << "yes";
            return 0;
        }
    }

    cout << "no";

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char board[5][6];
    string tar = "MAPOM";
    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < 5; i++)
    {
        swap(board[i][1], board[i][3]);
    }

    for (int i = 0; i < 5; i++)
    {
        string row(board[i]);

        if (row.find(tar) != string::npos)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "yes" << '\n';
    }
    else
    {
        cout << "no" << '\n';
    }

    return 0;
}
*/