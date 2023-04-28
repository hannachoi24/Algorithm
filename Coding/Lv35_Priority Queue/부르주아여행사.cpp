#include <iostream>
#include <queue>
using namespace std;

// 간선의 길이와 정보들을모두 Heap에 넣어두고 가장 비싼 간선 3개를 뽑아 출력

struct Node
{
    char from, to;
    int price;
};

priority_queue<Node> q;
int map[100][100];
int n;

bool operator<(Node a, Node tar)
{
    return tar.price > a.price;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] != 0)
            {
                char x = i + 'A';
                char y = j + 'A';
                q.push({x, y, map[i][j]});
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        Node ret = q.top();
        q.pop();

        cout << ret.from << "-" << ret.to << " " << ret.price << '\n';
    }

    return 0;
}
