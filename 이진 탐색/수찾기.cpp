#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100010];

void binarySearch(int key)
{
    int start = 0;
    int end = n - 1;
    int mid;

    while (end >= start)
    {
        mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            cout << 1 << '\n';
            return; // 종료
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << 0 << '\n'; // 이렇게 했는데도 찾고자 하는 값이 나오지 않으면 0 출력
    return;            // 종료
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // 입출력 빠르게 하기 위해

    cin >> n;

    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp; // 입력한 값을 arr배열에 담는다.
    }

    sort(arr, arr + n);

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        binarySearch(temp); // 숫자를 넣어주고 넣는 족족 바로 arr배열을 대상으로 이진탐색을 실행하여 0 또는 1을 출력
    }
    return 0;
}