#include <iostream>
using namespace std;

int main()
{
    char cube[3][3] = {
        {'0', '5', '4'},
        {'3', '0', '0'},
        {'0', '0', '1'}};

    char result[3][3];

    int k;
    cin >> k;

    // k번 굴림
    for (int i = 0; i < k; i++)
    {
        // cube의 좌표 (y, x) --> result의 좌표 (x, 2-y) 로 이동
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                result[x][2 - y] = cube[y][x];
            }
        }

        // 굴린 결과를 cube에 저장
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                cube[y][x] = result[y][x];
            }
        }
    }

    // 결과 출력
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (cube[y][x] == '0')
            {
                cout << "_";
            }
            else
            {
                cout << cube[y][x];
            }
        }
        cout << endl;
    }

    return 0;
}

/* 또 다른 코드
#include<iostream>
using namespace std;

int cube[3][3] = {
    0,5,4,
    3,0,0,
    0,0,1,
};

void spin()
{
    int x, y;
    int result[3][3];

    //돌린 결과를 result에 저장
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 3; x++) {
            result[x][2-y] = cube[y][x];
        }
    }

    //result --> cube로 Copy
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 3; x++) {
            cube[y][x] = result[y][x];
        }
    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        spin();
    }

    //출력
    int x, y;
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 3; x++) {
            if (cube[y][x] == 0) cout << "_";
            else cout << cube[y][x];
        }
        cout << "\n";
    }

    return 0;
}
*/