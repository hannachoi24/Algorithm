#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int n;
    cin >> name;
    cin >> n;
    string str[n];

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (str[i].find(name) == -1)
            cout << "X" << '\n';
        else
            cout << "O" << '\n';
    }

    return 0;
}