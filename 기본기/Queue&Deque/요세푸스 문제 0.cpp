#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> people;
    int n, k, removePeopleNum = 0;
    int current = 1;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        people.push(i);
    cout << "<";

    while (removePeopleNum != n)
    {
        while (1)
        {
            if (current++ % k == 0)
            {
                cout << people.front();
                people.pop();
                removePeopleNum++;
                break;
            }
            else
            {
                people.push(people.front());
                people.pop();
            }
        }

        if (removePeopleNum != n)
            cout << ", ";
    }

    cout << ">";
}

//  1. 사람을 모두 제거할 때까지 loop를 돈다

//  2-1. 일정 순번(k)째가 되면 그때 queue를 pop한 후 출력한다.

//  2-2. 일정 순번째가 아니면 queue의 가장 앞 원소를 가장 뒤쪽으로 옮겨준다.

//  3. < > 과 ,를 잘 출력해주도록 조절해준다.