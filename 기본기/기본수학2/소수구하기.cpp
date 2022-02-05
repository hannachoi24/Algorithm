#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int M, N;
    int rt; // 제곱근 저장하는 변수
    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        rt = sqrt(i);
        if (rt == 1 && i != 1)
        { // 2, 3인 경우
            cout << i << '\n';
            continue;
        }
        /* 제곱근을 저장하는 변수 rt는 int형이기 때문에, 검사 중인 i가 1, 2, 3이라면 rt에는 1이 저장될 것이다.
            2와 3은 소수이기 때문에 출력하지만 1은 소수가 아니기 때문에 if문에 1을 제외시키는 조건을 넣는다.
            continue를 실행하면 나머지 반복 부분을 실행하지 않고 다음 i로 넘어가 반복문을 실행.*/

        if (i % 2)
        { // 홀수일 경우
            for (int j = 2; j <= rt; j++)
            {
                if (!(i % j))
                    break;
                if (j == rt)
                {
                    cout << i << '\n';
                }
            }
        }
        /* 검사 중인 i가 짝수라면 2로 나눠지는 수이므로 소수가 아니다.
        i가 홀수인 경우에만 i의 제곱근인 2부터 rt까지 검사하여, 나누어 떨어지는 인수 j가 있는 경우 소수가 아니라고 판단하여 
        검사하는 for문을 break로 탈출한다.*/
    }
}