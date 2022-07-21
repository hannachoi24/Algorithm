#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrixBy90Degree(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> result(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[j][n - i - 1] = a[i][j];
        }
    }
    return result;
}
