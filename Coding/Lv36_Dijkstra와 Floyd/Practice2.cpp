#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 두 수(start, end) 입력 받고 갈 수 있는지 없는지 -> 다익스트라

struct Node
{
    int n;
    int price;
};

vector<vector<Node>> alist(6);
priority_queue<Node> q;
const int MAXI = 21e8;
int result[4] = {0, MAXI, MAXI, MAXI};

bool operator<(Node a, Node b)
{
    return a.price > b.price;
}

int start = 0;
int end = 3;

void init()
{
    for (int i = 0; i < 6; i++)
    {
        result[i] = MAXI;
    }
    result[start] = 0;

    alist[0] = {{1, 1}, {2, 1}, {3, 1}};
    alist[1] = {{2, 1}};
    alist[2] = {{3, 1}};
    alist[4] = {{3, 1}, {5, 1}};
    alist[5] = {{0, 1}};

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