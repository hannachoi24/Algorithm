#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Min(int A, int B)
{
    return A < B ? A : B;
}

int map[100][100];

int rotation(int x, int y, int xx, int yy)
{
    int min;
    int temp = map[x][y];
    min = temp;

    // 가장 왼쪽 변
    for (int i = x; i < xx; i++)
    {
        min = Min(min, map[i][y]);
        map[i][y] = map[i + 1][y];
    }
    // 가장 아래쪽 변
    for (int i = y; i < yy; i++)
    {
        min = Min(min, map[xx][i]);
        map[xx][i] = map[xx][i + 1];
    }
    // 가장 오른쪽 변
    for (int i = xx; i > x; i--)
    {
        min = Min(min, map[i][yy]);
        map[i][yy] = map[i - 1][yy];
    }
    // 가장 위쪽 변
    for (int i = yy; i > y; i--)
    {
        min = Min(min, map[x][i]);
        map[x][i] = map[x][i - 1];
    }
    map[x][y + 1] = temp;
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    int num = 1;

    // Map 세팅
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            map[i][j] = num++;
        }
    }

    // 회전 영역 지정
    for (int i = 0; i < queries.size(); i++)
    {
        int x = queries[i][0];
        x--;
        int y = queries[i][1];
        y--;
        int xx = queries[i][2];
        xx--;
        int yy = queries[i][3];
        yy--;
        // 각 최솟값들 answer벡터에 담기
        answer.push_back(rotation(x, y, xx, yy));
    }
    return answer;
}

int main()
{
    int rows = 6;
    int columns = 6;
    vector<int> queries{{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}};

    int sol = solution(rows, columns, queries);
    int size = sol.size();

    for (int i = 0; i < size; i++)
    {
        cout << sol << " ";
    }
}