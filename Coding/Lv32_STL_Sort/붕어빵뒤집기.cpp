#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int ROWS = 3; // 붕어빵 배열의 행 개수
const int COLS = 6; // 붕어빵 배열의 열 개수

// 붕어빵 배열
char bread[ROWS][COLS] = {
    {'A', 'B', 'C', 'E', 'F', 'G'},
    {'H', 'I', 'J', 'K', 'L', 'M'},
    {'N', 'O', 'P', 'Q', 'R', 'S'}};

char temp[ROWS][COLS];

// 붕어빵을 뒤집는 함수
void flipBread(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        if (bread[row][col] == '#')
        {
            bread[row][col] = temp[row][col];
        }
        else
        {
            bread[row][col] = '#';
        }
    }
}

int main()
{
    string input;
    cin >> input;

    // 빵판 복사(두번 뒤집힌 곳 원래 알파벳으로 되돌리기 위해)
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            temp[i][j] = bread[i][j];
        }
    }

    for (char c : input)
    {
        // 입력받은 문자열에 따라 붕어빵을 뒤집음
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (bread[row][col] == c)
                {
                    flipBread(row, col);
                    flipBread(row - 1, col);
                    flipBread(row + 1, col);
                    flipBread(row, col - 1);
                    flipBread(row, col + 1);
                }
            }
        }
    }

    // 결과 출력
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << bread[row][col];
        }
        cout << '\n';
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char map[3][7] = {"ABCEFG", "HIJKLM", "NOPQRS"};
int back[3][6] = { 0 };

int directY[5] = { -1, 0, 1, 0, 0 };
int directX[5] = { 0, 1, 0, -1, 0 };

void findXY(int* by, int* bx, int ch)
{
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 6; x++) {
            if (map[y][x] == ch) {
                *by = y;
                *bx = x;
                return;
            }
        }
    }
}

int main()
{
    string tar;
    cin >> tar;

    int tn = tar.length();
    int by, bx;

    for (int i = 0; i < tn; i++) {

        findXY(&by, &bx, tar[i]);

        for (int t = 0; t<5; t++) {
            int dy = by + directY[t];
            int dx = bx + directX[t];

            if (dy < 0 || dx < 0 || dy >= 3 || dx >= 6) continue;
            back[dy][dx] = (back[dy][dx] + 1) % 2;
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 6; x++) {
            if (back[y][x] == 0) cout << map[y][x];
            else cout << "#";
        }
        cout << "\n";
    }

    return 0;
}
*/