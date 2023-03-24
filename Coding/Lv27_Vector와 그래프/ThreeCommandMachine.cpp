#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v;
    string cmd;

    int n;
    int num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            v.push_back(num);
        }
        if (cmd == "printLast")
        {
            cout << v[v.size() - 1] << '\n';
        }
        if (cmd == "pop")
        {
            v.pop_back();
        }
    }

    return 0;
}
