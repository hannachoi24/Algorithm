#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int count = 0;
    int test_case;
    cin >> test_case;
    // 문서의 개수, 궁금한 문서 위치, 중요도
    int n, m, ipt;

    // 문서의 개수와 궁금한 문서 위치 정보 입력 받기, 필요한 큐 생성
    for (int i = 0; i < test_case; ++i)
    {
        count = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq; // 우선순위 큐

        // 중요도 정보 입력 받기
        for (int j = 0; j < n; ++j)
        {
            cin >> ipt;
            q.push({j, ipt});
            pq.push(ipt);
        }

        while (!q.empty())
        {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value)
            {
                pq.pop();
                ++count;
                if (index == m)
                {
                    cout << count << endl;
                    break;
                }
            }

            else
                q.push({index, value});
        }
    }
}

// 중요도가 나온 이 문제는 우선순위 큐를 사용하면 쉽게 풀 수 있다.
// 먼저 큐에 인덱스와 그 인덱스에 해당하는 중요도의 값을 넣는다.
// 그리고 우선순위 큐에 중요도를 넣게 되면 C++에서 제공하는 STL에서 자동으로 크기가 큰 순으로 정렬 해준다.
// 큐가 빌 때까지 현재 중요도와 우선순위 큐에 있는 중요도를 확인하고 현재 인덱스와 찾을 인덱스 값이 일치할때까지 갯수를 증가시키며 반복한다.
// 큐 STL 에서 pair 을 사용하면 2개의 데이터를 저장하기 위한 2개의 큐를 동시에 만들 수 있다.
// priority_queue 는 우선순위 큐 STL이다.