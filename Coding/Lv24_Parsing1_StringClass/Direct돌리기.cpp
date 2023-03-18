#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str[3][3] = {
        "BHC", "BBQ", "KFC",
        "MC", "7AVE", "PAPA",
        "DHC", "OBS", "MOMS"};

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int x, y;
    cin >> x >> y;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
            continue;

        cout << str[nx][ny];
    }

    return 0;
}