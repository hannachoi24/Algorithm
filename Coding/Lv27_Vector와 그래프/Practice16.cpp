#include <iostream>
#include <vector>
using namespace std;

// n칸에 input으로 들어온 정수를 넣고 출력

int main()
{
    int n, input;
    cin >> n >> input;

    vector<vector<int>> arr(n);

    for (int i = 0; i < input; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}