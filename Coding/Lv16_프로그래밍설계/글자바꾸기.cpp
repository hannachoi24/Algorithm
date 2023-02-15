#include <iostream>

using namespace std;

int main()
{
    char arr[10];
    char a, b;

    cin >> arr;
    cin >> a;
    cin >> b;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == a)
        {
            arr[i] = b;
        }
    }

    cout << arr;

    return 0;
}