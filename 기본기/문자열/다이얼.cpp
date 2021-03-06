#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    char alpha[26] = {
        0,
    };
    string ch;
    int result = 0, dial;
    cin >> ch;
    for (char e : ch)
    {
        alpha[e - 'A']++;
    }
    for (int i = 0; i <= 'Z' - 'A'; i++)
    {
        if (i == 'S' - 'A' || i == 'V' - 'A')
        {
            result += (i / 3 + 2) * alpha[i];
            continue;
        }

        if (alpha[i])
        {
            dial = i / 3 + 3;
            if (dial > 9)
            {
                result += 10 * alpha[i];
            }
            else
            {
                result += dial * alpha[i];
            }
        }
    }
    cout << result << endl;
    return 0;
}

/*
각 다이얼마다 알파벳이 보통 3개씩 들어있으며 마지막 다이얼과 마지막에서 3번째에 위치한 다이얼 2개만 알파벳을 4개 가지고 있는 것을 활용한 코드이다.
A, B, C를 각각 0, 1, 2로 보고 3을 나누어주면 0이라는 결과가 나오고 여기서 3을 더하면 A, B, C를 걸기 위해 걸리는 시간인 3초가 딱 나온다.
M, N, O까지만 해도 이 규칙이 잘 맞아떨어지다가 그 다음 다이얼에서 알파벳이 4개가 들어가면서 예외 사항이 생긴다. 
S는 본래 같은 다이얼에 있는 알파벳들보다 1초 더 걸린다. 
다음 알파벳에 있는 V 또한 같은 다이얼에 있는 알파벳들보다 1초 더 걸린다. 
이걸 이용해서 S와 V만 따로 예외처리해서 다른 알파벳들은 3을 더해주는걸 이 알파벳들만 2를 더해준다.
그럼 마지막 알파벳 4개는 어떻게 할까? 앞에 A, B, C를 0, 1, 2로 본 것처럼 V, W, X를 각각 21, 22, 23으로 볼 수 있으며 
여기서 3을 나누고 이 몫에 3을 더하면 10이라는 숫자가 나온다. 
원래는 V, W, X가 모두 10초가 걸려야하나, V가 예외처리 되었으므로 얘만 앞서 2를 더해서 9초가 걸리게끔 처리한다. 
그리고 W부터는 모두 10초가 걸리게끔 if문을 사용해 3을 나누고 몫에 3을 더한 값이 9가 넘으면 무조건 10초가 걸린다고 분류해버리는 것이다. 
그래서 Y, Z도 다이얼 거는데 10초가 걸린다고 분류된다.
알파벳을 다이얼 거는데 몇 초가 걸릴 지 분류하는 코드 앞에 알파벳이 각각 몇 개 있는지 분류해서 카운트하는 코드를 집어넣는다. 
그리고 이 알파벳의 개수와 알파벳을 다이얼 거는데 걸리는 시간을 곱해서 result 결과 값에 차곡차곡 더해주고 
마지막에 result를 출력하면 전체 다이얼을 거는데 걸리는 시간이 출력된다. */