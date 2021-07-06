#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> arr;

int main()
{
    cin >> n >> c;

    // 전체 집의 좌표 정보를 입력 받기
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행을 위해 정렬 수행
    sort(arr.begin(), arr.end());

    int start = 1;                 // 가능한 최소 거리(min gap)
    int end = arr[n - 1] - arr[0]; // 가능한 최대 거리(max gap)
    int result = 0;

    while (start <= end)
    {
        // mid는 가장 인접한 두 공유기 사이의 거리(gap)을 의미
        int mid = (start + end) / 2;
        // 첫번 째 집에는 무조건 공유기를 설치한다고 가정
        int value = arr[0];
        int cnt = 1;
        // 현재의 mid 값을 이용해 공유기를 설치
        for (int i = 0; i < n; i++)
        { // 앞에서부터 차근차근 설치
            if (arr[i] >= value + mid)
            {
                value = arr[i];
                cnt += 1;
            }
        }
        // C개 이상의 공유기를 설치할 수 있는 경우, 거리를 증가시키기
        if (cnt >= c)
        {
            start = mid + 1;
            result = mid; // 최적의 결과를 저장
        }

        // C개 이상의 공유기를 설치 할 수 없는 경우, 거리를 감소시키기
        else
        {
            end = mid - 1;
        }
    }

    cout << result << '\n';
}