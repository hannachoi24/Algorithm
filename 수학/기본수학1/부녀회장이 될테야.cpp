#include <iostream>
using namespace std;

int main()
{
    int t;
    int k, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int res[15][14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        cin >> k >> n;
        for (int j = 1; j <= k; j++)
        {
            for (int l = 0; l < n; l++)
            {
                for (int m = 0; m <= l; m++)
                {
                    res[j][l] += res[j - 1][m];
                }
            }
        }
        cout << res[k][n - 1] << endl;
    }
}