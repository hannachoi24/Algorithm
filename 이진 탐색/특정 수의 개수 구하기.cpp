#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int count(vector<int> &v, int leftValue, int rightValue)
{
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

int n, x;
vector<int> v;

int main()
{
    // 데이터의 개수 n, 찾고자 하는 값 x 입력받기
    cin >> n >> x;

    // 전체 데이터 입력 받기
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // 값이 [x, x] 범위에 있는 데이터의 개수 계산
    int cnt = count(v, x, x);

    if (cnt == 0)
    {
        cout << -1 << '\n';
    }

    else
    {
        cout << cnt << '\n';
    }
}