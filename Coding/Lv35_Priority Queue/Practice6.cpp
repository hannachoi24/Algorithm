#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int n;
    int price;
};

vector<vector<int>> alist(6);
priority_queue<Node> q;
int result[6];

bool operator<(Node a, Node b)
{
    return a.price > b.price;
}

void init()
{
    for (int i = 0; i < 6; i++)
        result[i] = 21e8;
    result[0] = 0;

    alist[0] = {{1, 5}, {2, 10}, {3, 7}};
    alist[1] = {{0, 5}, {5, 9}};
    alist[2] = {{5, 1}};
    alist[3] = {{4, 1}};
    alist[4] = {{5, 6}};

    // 출발 지점
    q.push({0, 0});
}

int main()
{
    init();

    while (!q.empty())
    {
        Node now = q.top();
        q.pop();

        // 1. 최신 데이터인지 아닌지
        if (result[now.n] < now.price)
            continue;

        // 2. 다음 갈 수 있는 곳 찾기
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
