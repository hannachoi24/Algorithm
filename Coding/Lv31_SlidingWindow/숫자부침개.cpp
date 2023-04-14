#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string num;
    int n;
    cin >> num >> n;

    for (int i = 0; i < n; i++)
    {
        num = to_string(stoi(num) * 2);
        reverse(num.begin(), num.end());
    }

    cout << num;

    return 0;
}
