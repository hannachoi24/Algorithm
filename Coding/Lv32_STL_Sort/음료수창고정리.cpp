#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> drink(5);

    for (int i = 0; i < 5; i++)
    {
        string str;
        cin >> str;
        for (char c : str)
        {
            drink[i].push_back(c - '0');
        }
    }

    int line1, line2;
    cin >> line1 >> line2;

    sort(drink[line1].begin(), drink[line1].end());
    sort(drink[line2].begin(), drink[line2].end());

    for (int i = 0; i < 5; i++)
    {
        int size = drink[i].size();
        if (size == 0)
        {
            cout << "empty";
            continue;
        }
        cout << drink[i][0] << " ";
    }

    return 0;
}