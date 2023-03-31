#include <iostream>
#include <queue>
#include <string>
using namespace std;

string name = "ACBQTPR";

int map[7][7] = {
    0, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 1};

queue<char> q;

int main()
{
    q.push(0);

    while (!q.empty())
    {
        int now = q.front();
        cout << name[now];
        q.pop();

        for (int i = 0; i < 7; i++)
        {
            if (map[now][i] == 0)
                continue;

            q.push(i);
        }
    }

    return 0;
}