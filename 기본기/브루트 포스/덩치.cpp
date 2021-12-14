#include <iostream>
using namespace std;

int main()
{
    int n;
    int arr[51][2] = {};
    int grade[51];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        grade[i] = 1; // 결과 배열 초기화
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
                grade[i]++;
        }
    }

    for (int i = 0; i < n; i++)

        cout << grade[i] << " ";
    cout << '\n';
}