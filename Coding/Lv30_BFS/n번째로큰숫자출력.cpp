#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v = {1, 5, 4, 2, -5, -7};

int main()
{
    int idx;
    cin >> idx;

    sort(v.begin(), v.end(), greater<int>());

    cout << v[idx - 1];

    return 0;
}