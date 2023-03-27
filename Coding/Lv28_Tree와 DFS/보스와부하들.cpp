#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int boss = -1;
    for (int i = 0; i < n; i++)
    {
        if (graph[i][0] == 1)
        {
            boss = i;
            break;
        }
    }
    cout << "boss:" << boss << endl;

    cout << "under:";
    bool is_first = true;
    for (int i = 0; i < n; i++)
    {
        if (graph[0][i] == 1 && i != 0)
        {
            if (is_first)
            {
                cout << i;
                is_first = false;
            }
            else
            {
                cout << " " << i;
            }
        }
    }
    cout << '\n';

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int map[10][10];
int n;

void input()
{
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }
}

int main()
{
    input();

    //보스 찾아서 출력하기
    cout << "boss:";
    for (int y = 0; y < n; y++) {
        if (map[y][0] == 1) cout << y;
    }
    cout << endl;

    //부하 찾아서 출력하기
    cout << "under:";
    for (int x = 0; x < n; x++) {
        if (map[0][x] == 1) cout << x << " ";
    }
    cout << endl;

    return 0;
}
*/
