#include <iostream>
#include <cstring>
using namespace std;

// strlen: 문자열 길이

int main()
{
    char arr[5];
    cin >> arr;

    int len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = len - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    return 0;
}