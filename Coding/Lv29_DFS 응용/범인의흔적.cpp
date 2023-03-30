#include <iostream>
using namespace std;

int evid[7] = {-1, 0, 0, 1, 2, 4, 4};
int timeStamp[7] = {8, 3, 5, 6, 8, 9, 10};

void backtrack(int cur)
{
    if (cur == -1) // 범인을 잡았으면 종료
        return;
    backtrack(evid[cur]); // 이전 위치로 재귀호출
    if (evid[cur] == -1)
    {
        cout << cur << "번index(출발)\n";
    }
    else
    {
        cout << cur << "번index(" << timeStamp[cur] << "시)\n";
    }
}

int main()
{
    int start;
    cin >> start;
    backtrack(start);
    return 0;
}