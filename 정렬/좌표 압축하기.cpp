#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, cnt = 0;
vector<pair<int, int>> v, ans;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;            // 1. 입력 받기(입력받은 순서가 order)
        v.push_back({x, i}); // {xi, 기존 순서}
    }

    sort(v.begin(), v.end()); // 2. xi의 크기대로 2차원 v벡터 정렬

    ans.push_back({v[0].second, 0}); // {위 정렬에 대한 order, 0}

    for (int i = 1; i < n; i++)
    {
        if (v[i - 1].first == v[i].first)      // 3. 앞 뒤의 xi 값을 비교해 같으면 cnt(카운트)를 그대로 유지
        {                                      // Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
            ans.push_back({v[i].second, cnt}); // {v벡터 xi 정렬에 대한 order, xi'}
        }
        else // 앞 뒤의 xi값이 다르면 ++cnt
        {
            ans.push_back({v[i].second, ++cnt}); // {v벡터 xi 정렬에 대한 order, xi'}
        }
    }
    sort(ans.begin(), ans.end()); // 4. ans벡터를 다시 오름차순으로 정렬하고 출력

    for (int i = 0; i < n; i++)
    {
        cout << ans[i].second << " ";
    }
}

/* 1. 입력받기(입력받은 순서가 order)

<v벡터>

Xi	order
2	0
4	1
-10	2
4	3
-9	4
 
2. Xi의 크기대로 2차원 v벡터 정렬하기

<v벡터>

Xi	order
-10	2
-9	4
2	0
4	1
4	3
 
3. 앞 뒤의 Xi값을 비교해서 같으면 cnt(카운트)를 그대로 유지하고 다르다면 ++cnt을 해줍니다.

<ans벡터>

order	Xi'
2	    0
4	    1
0	    2
1	    3
3	    3

v[0].first = -10이고 가장 처음의 값이므로 X0' = 0

v[1].first = -9이고 이전값(v[0].first = -10)과 다르므로 X1' = 1

v[2].first = 2이고 이전값(v[1].first = -9)과 다르므로 X2' = 2

v[3].first = 4이고 이전값(v[2].first = 2)과 다르므로 X3' = 3

v[4].first = 4이고 이전값(v[3].first = 4)과 같으므로 X4' = 3

4. ans 벡터를 다시 오름차순으로 정렬하고 정답 출력

<ans벡터>

order	Xi'
0	    2
1	    3
2	    0
3	    3
4	    1
*/