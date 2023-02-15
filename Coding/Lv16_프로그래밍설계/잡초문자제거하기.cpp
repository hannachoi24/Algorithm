#include <iostream>
#include <string>
using namespace std;

int main()
{
    string arr;
    int idx;

    cin >> arr >> idx;

    int len = arr.length();

    for (int i = idx; i < len - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr.pop_back();
    cout << arr;
    //for (int i = 0; i < len - 1; i++)
    //{
    //   cout << arr[i];
    //}

    return 0;
}
