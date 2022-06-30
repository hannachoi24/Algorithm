#include <iostream>
using namespace std;

// 세 개의 합을 구할 때 m보단 작되 제일 큰 수를 구하면 된다. 브루트 포스로 하나씩 비교해가면서 조건에 맞는 수를 찾으면 된다.

int main()
{

    int arr[100];
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int result = 0, sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++) // j는 i + 1 이기 때문에 1에서 시작
        {
            for (int k = j + 1; k < N; k++) // k는 j + 1 이기 때문에 2에서 시작
            {
                sum = arr[i] + arr[j] + arr[k];
                if (sum > result && sum <= M)
                    result = sum;
            }
        }
    }

    cout << result;

    return 0;
}