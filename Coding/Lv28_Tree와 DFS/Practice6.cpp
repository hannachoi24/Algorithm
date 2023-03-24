#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<char>> v(3);

    v[0] = {'A', 'B', 'T'};
    v[2] = {'R', 'S'};

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v[i].size() - 1; j >= 0; j--)
        {
            cout << v[i][j];
        }

        cout << '\n';
    }

    return 0;
}