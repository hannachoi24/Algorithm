#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> trees;

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int h; // 나무 높이
        cin >> h;
        trees.push_back(h);
    }

    int start = 0;
    int end = 1e9;
    int result = 0;

    while (start <= end)
    {
        long long int total = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < n; i++)
        {
            if (mid < trees[i]) // 중간길이보다 나무 높이가 더 길면
                total += trees[i] - mid;
        }

        if (total < m)
        {
            end = mid - 1;
        }
        else
        {
            result = mid;
            start = mid + 1;
        }
    }

    cout << result << '\n';
}