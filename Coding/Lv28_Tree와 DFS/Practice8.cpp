#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 인접 리스트

int main()
{
    string name = "DUSRK";
    vector<vectortor<int>> alist(5);

    alist[0] = {1, 3, 4};
    alist[1] = {2, 3};
    alist[3] = {2, 4};
    alist[4] = {1, 3};

    int n;
    cin >> n;

    for (int i = 0; i < alist[n].size(); i++)
    {
        if (alist[n][i] ==)
        {
            cout << name[alist[n][i]];
        }
    }

    return 0;
}