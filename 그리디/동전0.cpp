#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // n은 종류, k는 가치의 합
    int n, k, answer = 0;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        answer += k / A[i];
        k %= A[i];
    }

    cout << answer;

    return 0;
}
