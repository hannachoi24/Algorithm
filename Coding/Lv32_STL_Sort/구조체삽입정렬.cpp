#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int num;
    char ch;
};

bool cmp(Node a, Node b)
{
    if (a.num == b.num)
        return a.ch < b.ch;

    return a.num < b.num;
}

int main()
{
    int n;
    cin >> n;

    Node arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].num >> arr[i].ch;
    }

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].num << " " << arr[i].ch << '\n';
    }

    return 0;
}