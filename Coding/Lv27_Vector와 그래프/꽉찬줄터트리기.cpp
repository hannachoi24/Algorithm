#include <iostream>
using namespace std;

int main()
{
    int block[5][4];

    // 블록 상태 입력 받기
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> block[i][j];
        }
    }

    // 꽉 찬 줄 찾기
    for (int i = 0; i < 5; i++)
    {
        bool is_full = true;
        for (int j = 0; j < 4; j++)
        {
            if (block[i][j] == 0)
            {
                is_full = false;
                break;
            }
        }
        if (is_full)
        {
            // 꽉 찬 줄을 지우기
            for (int j = i; j > 0; j--)
            {
                for (int k = 0; k < 4; k++)
                {
                    block[j][k] = block[j - 1][k];
                }
            }
            for (int k = 0; k < 4; k++)
            {
                block[0][k] = 0;
            }
        }
    }

    // 블록 상태 출력하기
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << block[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
