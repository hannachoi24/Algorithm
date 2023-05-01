#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 3번으로 가는 가중치 중 최대 비용 선택 후 최대 비용들 중 최소값 구하기

struct Node
{
    int n;
    int price;
};

bool operator<(Node a, Node b)
{
    return a.price > b.price;
}

priority_queue<Node> q;

vector<vector<int>> alist(5);
int result[5];

void init()
{
    alist[0] = {{1, 8}, {4, 4}, {3, 10}};
    alist[1] = {{2, 1}};
    alist[2] = {{3, 2}};
    alist[4] = {{2, 3}, {3, 5}};

    q.push({0, 0});

    for (int i = 0; i < 5; i++)
    {
        result[i] = 21e8;
    }

    result[0] = 0;
}

int main()
{
    init();

    while (!q.empty())
    {
        Node now = q.top();
        q.pop();

        if (result[now.n] < now.price)
            continue;

        for (int i = 0; i < alist[now.n].size(); i++)
        {
            Node next = alist[now.n][i];
            int bigNum = max(now.price, next.price);

            if (result[next.n] > bigNum)
            {
                result[next.n] = bigNum;
                q.push({next.n, bigNum});
            }
        }
    }

    return 0;
}