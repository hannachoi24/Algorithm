#include <iostream>
using namespace std;

int arr[4] = {5, 2, 5, 7};

getCount(int n)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == n)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    cout << getCount(n);

    return 0;
}