#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

/* 이번에는 pair에서 second를 기준으로 정렬하는 문제이다.
이런 경우에는 기본 sort를 쓰지 않고 compare함수를 정의해서 풀이하면 된다.
STL의 sort함수는 compare라는 비교 함수를 직접 인자로 전달할 수 있기 때문에, 
필요에 따라서 수정하여 sort를 진행할 수 있다는 사실을 짚고 넘어가면 될 것 같다. */

bool compare(pair<long, long> a, pair<long, long> b)
{
    if (a.second == b.second)
        return a.first < b.first; // y좌표가 같으면 x좌표가 증가하는 순으로
    else
        return a.second < b.second; // y좌표가 증가하는 순으로
}

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

    sort(arr.begin(), arr.end(), compare); // 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬

    for (int i = 0; i < num; i++)
    {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}