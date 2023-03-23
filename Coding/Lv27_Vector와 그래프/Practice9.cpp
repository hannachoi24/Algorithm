#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> vec = {"BTBTBTS", "KFKFKFC", "MBMBMBM"};

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = vec[i].length() - 1; j >= 0; j--)
        {
            cout << vec[i][j];
        }
        cout << '\n';
    }

    return 0;
}