#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/* 원래의 순서를 손상시키지 않으면서 정렬하는것을 stable sort라고 한다.

본 문제는 C++의 sort처럼 algorithm 헤더에 들어있는 stable_sort를 통해서 풀이가 가능하다.
stable_sort라는 STL 함수가 있다는것을 알고 있다면 간단히 풀이가 가능하다.

만약 직접구현하려고하면 버블소트나 힙소트등의 stable sort류 정렬 알고리즘을 사용하면 된다. */

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> arr;
    pair<int, string> tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    stable_sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}