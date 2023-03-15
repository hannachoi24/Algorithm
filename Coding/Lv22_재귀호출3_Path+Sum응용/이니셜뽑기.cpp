#include <iostream>
using namespace std;

int main()
{
    char map[4][5][4] = {
        " # ",
        "# #",
        "###",
        "# #",
        "# #",

        "###",
        "# #",
        "###",
        "# #",
        "###",

        "###",
        "# #",
        "#  ",
        "# #",
        "###",

        "## ",
        "# #",
        "# #",
        "# #",
        "## "};

    int n;
    cin >> n;

    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            cout << map[n][j][k];
        }
        cout << '\n';
    }

    return 0;
}