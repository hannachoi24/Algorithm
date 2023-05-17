#include <iostream>
#include <vector>
#include <cmath>
#define MAX 51

using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX];
int answer = 21e8;

struct Node
{
    int x, y;
};

vector<Node> home;
vector<Node> chicken;

void distOfChicken()
{
    int sum = 0;

    for (Node h : home)
    {
        // 각 집에서 선정된 M개의 치킨집 간에 가장 가까운 거리
        int dist = 21e8;

        for (int i = 0; i < chicken.size(); i++)
        {
            if (visited[i])
            {
                int d = abs(h.x - chicken[i].x) + abs(h.y - chicken[i].y);
                dist = min(d, dist);
            }
        }

        sum += dist;
    }
    answer = min(answer, sum);
}

void run(int level, int start)
{
    if (level == M)
    {
        distOfChicken();
        return;
    }

    for (int i = start; i < chicken.size(); i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        run(level + 1, i + 1);
        visited[i] = false;
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
                home.push_back({i, j});
            else if (map[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    run(0, 0);

    cout << answer << '\n';

    return 0;
}