#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(4);

int main()
{
    v[0].push_back(4);
    v[0].push_back(2);
    v[0].push_back(5);
    v[0].push_back(1);
    v[0].push_back(1);

    v[1].push_back(3);
    v[1].push_back(4);
    v[1].push_back(2);

    v[3].push_back(1);
    v[3].push_back(1);
    v[3].push_back(2);
    v[3].push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
        cout << '\n';
    }

    return 0;
}