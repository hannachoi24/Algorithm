#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    // 큐의 크기, 뽑는 수의 개수
    int n, m;
    int num; // 뽑아내려고 하는 수
    int index;
    int count = 0;
    deque<int> d;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        d.push_back(i);
    }

    while (m--)
    {
        cin >> num;

        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] == num)
            {
                index = i;
                break;
            }
        }

        if (index < d.size() - index)
        {
            while (1)
            {
                if (d.front() == num)
                {
                    d.pop_front();
                    break;
                }
                ++count;
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else
        {
            while (1)
            {
                if (d.front() == num)
                {
                    d.pop_front();
                    break;
                }
                ++count;
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }

    cout << count << endl;

    return 0;
}

// 덱 문제이다.

// 원형 큐에서 M개의 수를 빼낼때 최소 걸리는 횟수를 구하는 문제
// 좌, 우로 움직일 수 있으며 front를 뺄때는 횟수가 증가하지 않는다.

// 1. 덱에 1~N까지의 값을 넣는다.
// 2. 찾아야하는 숫자의 인덱스 번호를 확인한다.
// 3. 인덱스 번호를 통해 왼쪽으로 가는 경우와
//    오른쪽으로 가는 경우에 대해서 빠른 경로를 찾는다.
// 4. 빠른 방향으로 이동하면서 횟수만큼 카운트를 증가시킨다.
// 5. 찾은 수를 pop시킨다.
// 6. 찾는 수들을 다 찾을 때 까지 2~5를 반복한다.