#include <iostream>
using namespace std;

void star(int i, int j, int n)
{
    if (i / n % 3 == 1 && j / n % 3 == 1)
    {
        cout << " ";
    }
    else if (n / 3 == 0)
    {
        cout << "*";
    }
    else
    {
        star(i, j, n / 3);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            star(i, j, n);
        }
        cout << '\n';
    }
}

/* N=3 일 때, 가운데 (1,1)이 비어있는 모습을 볼 수 있다.
비어있는 칸의 가로 좌표를 보면, 1, 4, 7, 10, 13, 16, 19, 33, 25이다.
이는 i % 3 == 1 로 일반화할 수 있다.
N=9일 때, 중앙 빈 부분의 좌표를 살펴보면
(3,3), (3,4), (3,5), (4,3), (4,4), (4,5), (5,3), (5,4), (5,5)
좌표에서 중앙의 빈 곳들은 (i / 3) % 3 == 1 && (j / 3) % 3 == 1 로 일반화할 수 있다.
이를 바탕으로 빈칸임을 검사하는 조건을 작성하면
(i / n) % 3 == 1 && (j / n) % 3 == 1
이 조건식을 재귀적으로 검사하면 문제를 해결할 수 있다.
N으로 검사했을 때의 빈칸은 N/3으로 검사해도 어짜피 빈칸이므로 빈칸을 바로 출력하고,
빈칸이 아닌 경우 재귀적으로 star(i, j, n / 3)과 같이 넘겨 검사 */