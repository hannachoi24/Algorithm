#include <iostream>

using namespace std;

int main()
{
    int a, b;
    string str;
    cin >> a >> b >> str;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < b; k++)
            {
                cout << str;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}