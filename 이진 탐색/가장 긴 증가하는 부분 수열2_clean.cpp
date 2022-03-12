#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 문제 접근 과정

 LIS 문제이다. 시간 복잡도 O(NlogN)으로 풀었다.

1. 크기 값을 입력 받는다.
2. 벡터 값을 입력받는데 조건문을 활용하여 입력받는다.
3. Lower bound로 접근하여 시간 복잡도 O(NlogN)이 나오도록 풀 수 있다. */

int n;
vector<int> v;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (v.empty() || v.back() < num)
        {
            v.push_back(num);
        }
        else
        {
            *lower_bound(v.begin(), v.end(), num) = num;
        }
    }
    cout << v.size();
}