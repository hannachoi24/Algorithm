#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 7, 4, 1, 2};

    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    arr.pop_back();
    arr.pop_back();

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }

    return 0;
}