#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int a[100] = {0};
bool v[100] = {false};

void Permutation(vector<int> &data, int start, int index, int n, int m)
{

    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < n; i++)
    {
        if (!v[i])
        {
            v[i] = true;
            a[index] = data[i];
            Permutation(data, i, index + 1, n, m);
            v[i] = false;
        }
    }
}

int main()
{

    int n, m = 5;

    cin >> n;

    vector<int> data;

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    sort(data.begin(), data.end());

    Permutation(data, 0, 0, n, m);

    cout << '\n';

    return 0;
}