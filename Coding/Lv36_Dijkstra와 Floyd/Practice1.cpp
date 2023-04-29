#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Dijkstra

struct Node
{
    int n;
    int price;
};

vector<vector<Node>> alist(4);
priority_queue<Node> q;
const int MAXI = 21e8;
int result[4] = {0, MAXI, MAXI, MAXI};

bool operator<(Node a, Node b)
{
    return a.price > b.price;
}

void init()
{
    for (int i = 0; i < 4; i++)
    {
        result[i] = MAXI;
    }
    result[0] = 0;

    alist[0] = {{2, 20}, {1, 5}, {3, 30}};
    alist[1] = {{2, 10}, {3, 35}};
    alist[2] = {{3, 20}, {0, 1}};

    // 출발 지점
    q.push({0, 0});
}

int main()
{
    while (!q.empty())
    {
        Node now = q.top();
        q.pop();

        // 1. 최신 데이터인가?
        if (result[now.n] < now.price)
            continue;

        // 2. 큐 등록
        for (int i = 0; i < alist.size(); i++)
        {
            Node next = alist[now.n][i];

            int priceSum = now.price + next.price;

            if (result[next.n] > priceSum)
            {
                result[next.n] = priceSum;
                q.push({next.n, priceSum});
            }
        }
    }

    return 0;
}