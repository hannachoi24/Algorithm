#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, tmp, min = 1e9, max = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        if (max < tmp)
        {
            max = tmp;
        }
        if (min > tmp)
        {
            min = tmp;
        }
    }
    cout << min * max;

    return 0;
}