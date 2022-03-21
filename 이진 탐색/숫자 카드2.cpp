#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        int lower = lower_bound(arr.begin(), arr.end(), num) - arr.begin(); // arr 처음 부터 끝까지 탐색하면서 num 이상의 숫자가 처음으로 나오는 위치의 인덱스 번호 반환
                                                                            // lower_bound의 반환형은 Iterator 이므로 실제로 몇 번째 인덱스인지 알고 싶다면,
                                                                            // lower_bound 값에서 배열 첫 번째 주소를 가리키는 배열의 이름을 빼 주면 된다.
        int upper = upper_bound(arr.begin(), arr.end(), num) - arr.begin();

        if (upper == n - 1 && arr[n - 1] == num)
            upper++;

        cout << upper - lower << " ";
    }

    return 0;
}

/* 
<lower_bound>
용도 : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
사용 조건 : 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 함

<upper_bound>
용도 : 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
사용 조건 : 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 함

이런 문제에서 활용할 수 있다.
👆 오름차순 정렬된 자료에서 특정 범위에 속하는 숫자들이 몇 개 있는지 탐색하고자 할 때

이진 탐색 기반의 lower, upper_bound를 사용하면 시간 복잡도를 효과적으로 줄일 수 있다.

(예) {1,3,5,5,7,8,8,10,10,11,13} 에서 5 이상 11 이하의 숫자가 몇 개인지 구할 때

✌ 오름차순 정렬된 자료에서 특정한 숫자가 몇 번 나오는지 탐색하고자 할 때

이진 탐색 기반의 lower, upper_bound를 사용하여 O(logN)으로 탐색 가능하다. O(N)이 불가능 할 때 유용하게 사용할 수 있다.
ex) 5의 개수 구하기 
{1,3,5,5,5,8,8,10,10,11,13}에서 5보다 큰 숫자가 처음으로 나오는 위치 - 5 이상의 숫자가 처음으로 나오는 위치를 한 값이다.
upper_bound(arr.begin(), arr.end(), 5) - lower_bound(arr.begin(), arr.end(), 5);
*/

/*
10
6 3 2 10 10 10 -10 -10 7 3  ->  -10 -10 2 3 3 6 7 10 10 10
8
10 9 -5 2 3 4 5 -10
*/