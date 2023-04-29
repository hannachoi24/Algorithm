#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 두 수(start, end) 입력 받고 갈 수 있는지 없는지 -> BFS

struct Node
{
    int n;
    int price;
};

vector<vector<Node>> alist(6);
queue<Node> q;
const int MAXI = 21e8;
int visited[6];

bool operator<(Node a, Node b)
{
    return a.price > b.price;
}

int start = 0;
int end = 3;

int main()
{
    alist[0] = {{1, 1}, {2, 1}, {3, 1}};
    alist[1] = {{2, 1}};
    alist[2] = {{3, 1}};
    alist[4] = {{3, 1}, {5, 1}};
    alist[5] = {{0, 1}};

    // 출발 지점
    q.push({0, 0});

    visited[0] = 1;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < alist[now.n].size(); i++)
        {
            Node next = alist[now.n][i];

            if (visited[next.n] == 1)
                continue;

            visited[next.n] = 1;
            q.push(next);
        }
    }

    return 0;
}