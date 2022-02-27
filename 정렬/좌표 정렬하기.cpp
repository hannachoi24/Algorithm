#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

/* utility 헤더파일에 존재하는 pair 자료형을 활용하여 sort를 진행하면 되는 문제이다.
pair 경우 first가 같으면 second로 비교하게끔 이미 sort함수에서 구현이 되어 있기 때문에 STL의 sort를 활용하면 된다.
STL의 sort함수가 pair 자료형에서 완벽하게 동작한다는 사실을 알면 매우 금방 풀 수 있는 문제이다.
좌표의 경우 무조건 pair 자료형을 쓰는게 편하다는 사실을 알고 넘어가자. */

int main()
{
    int num;
    cin >> num;
    vector<pair<long, long>> arr;
    pair<long, long> tmp;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end()); // 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬

    for (int i = 0; i < num; i++)
    {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}