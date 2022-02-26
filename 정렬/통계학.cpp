#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[500001];
int cnt[8001];
int n, a, b, c, d;
int sum = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i] + 4000]++;
    }

    sort(arr, arr + n);

    int flag;
    int max = 0;

    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] > max)
        {
            max = cnt[i];
            flag = i; // flag는 i 번째
        }
    }

    for (int i = flag + 1; i < 8001; i++)
    {
        if (cnt[i] == max)
        {
            flag = i;
            break;
        }
    }

    a = round(double(sum) / n); // 산술평균(N개의 수들의 합을 N으로 나눈 값)
    b = arr[(n - 1) / 2];       // 중앙값
    c = flag - 4000;            // 최빈값
    d = arr[n - 1] - arr[0];    // 범위(N개의 수들 중 최댓값과 최솟값의 차이)

    cout << a << '\n';
    cout << b << '\n';
    cout << c << '\n';
    cout << d << '\n';
}

/* 1. a는 산술평균

산술 평균의 경우 일반적으로 평균을 구하는 방식. round 함수가 연산하기 전 sum 변수를 double형으로 캐스팅하여 소수점이 날아가지 않게 한다.

2. b는 중앙값

N은 항상 홀수로만 주어지므로 coordinate 배열을 정렬 한 뒤 (N-1)/2 번째 배열 값이 중앙값이 된다.

3. c는 최빈값 (최빈값이 여러개일 경우 최빈값들 중 2번째로 작은 수)

cnt 배열의 경우 첫번째 값인 cnt[0]은 -4000이 나온 개수, 8001번째 값인 cnt[8000]은 4000이 나온 개수이다. 수들을 입력받으면서 해당 인덱스의 cnt값을 ++ 해주었으며, 입력을 종료한 뒤 for문을 통해 cnt[0]부터 cnt[8000]까지 가장 큰 값을 탐색한다.
이때 if(cnt[i] >max)라는 조건으로 인해 flag값은 최빈값들 중 가장 작은 값의 인덱스가 된다. 그리고 다시 해당 flag값 다음 인덱스부터 8001번째 cnt배열 값까지 탐색을 하는데, 위에서 저장된 max값과 같은 값을 가지는 cnt배열 값이 등장하지 않는다면(중복되는 최빈값이 없는 경우) for문은 종료되고 만약 max값과 같은 값을 가지는 cnt배열 값이 등장한다면(중복되는 최빈값이 있는 경우) 그 값이 최빈값들 중에서 2번째로 작은 값이기 때문에 flag값을 해당 인덱스로 변경 후 break문을 통해 for문을 종료한다.

4. d는 범위

coordinate 배열은 정렬되어 있으므로 배열의 끝값과 배열의 처음값을 빼주면 값의 범위가 나온다. */