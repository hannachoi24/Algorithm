#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 7, 4, 1, 2};

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }

    return 0;
}