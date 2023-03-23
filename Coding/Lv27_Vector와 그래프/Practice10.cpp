#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> vec(n + 1);

    string maxStr;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];

        if (vec[i].length() > maxStr.length())
        {
            maxStr = vec[i];
        }
    }

    cout << maxStr;

    return 0;
}

/* 또 다른 코드
int main()
{
    int n;
    cin >> n;

    vector<string> vec;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        vec.push_back(temp);
    }

    string maxStr;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];

        if (vec[i].length() > maxStr.length())
        {
            maxStr = vec[i];
        }
    }

    cout << maxStr;

    return 0;
}
*/