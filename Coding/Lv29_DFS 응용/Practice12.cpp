#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int n;
    int weight;
};

vector<vector<Node>> v(4);
bool visited[4] = {false};

void dfs(int now, int sum)
{
    if (now == 2)
    {
        cout << sum << " ";
        return;
    }

    for (int i = 0; i < v[now].size(); i++)
    {
        Node next = v[now][i]; // next는 다음 갈 곳의 정보를 담고 있는 구조체 변수

        if (visited[next.n] == true)
            continue;
        visited[next.n] = true;
        dfs(next.n, sum + next.weight);
        visited[next.n] = false;
    }
}

int main()
{
    v[0] = {{1, 5}, {3, 8}};
    v[1] = {{2, 6}};
    v[3] = {{1, 7}, {2, 9}};

    dfs(0, 0);

    return 0;
}