#include <iostream>
using namespace std;

/* 왼쪽 그림과 같은sketchbook 구조체를 정의하고,구조체 변수 1개를 만들어 주세요.
이미지에 들어갈 내용을구조체 변수안 image char배열에 입력받고,
어떤 무늬로 구성되어 있는지알파벳 순서대로 출력하세요.
(입력되는 문자는 모두 대문자입니다)
*/

// 구조체 정의
struct sketchbook
{
    char image[3][4];
};

int dat[200];

int main()
{
    sketchbook SB; // 구조체 변수

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> SB.image[i][j];

            dat[SB.image[i][j]] = 1;
        }
    }

    for (int k = 'A'; k <= 'Z'; k++)
    {
        if (dat[k] == 1)
        {
            cout << (char)k;
        }
    }

    return 0;
}