#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    /* 방법2
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    } */

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        cout << vec[i];
    }

    return 0;
}