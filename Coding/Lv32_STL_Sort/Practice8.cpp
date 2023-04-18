#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {3, 1, 5, 2, 6, 8};

    sort(v.begin(), v.end());

    for (auto i = v.begin(); i != v.end(); ++i)
    {
        cout << *i;
        << " ";
    }

    return 0;
}
