#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int number[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> number[i];
    }

    string command;
    cin >> command;

    bool visited[10] = {false}; // 중복 출력 방지를 위한 배열

    for (char c : command)
    {
        if (c == 'm')
        {
            int min_value = 10; // 초기값 설정
            for (int i = 0; i < 6; i++)
            {
                if (number[i] < min_value && !visited[number[i]])
                {
                    min_value = number[i];
                }
            }
            cout << min_value;
            visited[min_value] = true;
        }
        else if (c == 'x')
        {
            int max_value = -1; // 초기값 설정
            for (int i = 0; i < 6; i++)
            {
                if (number[i] > max_value && !visited[number[i]])
                {
                    max_value = number[i];
                }
            }
            cout << max_value;
            visited[max_value] = true;
        }
    }
    cout << '\n';

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int number[6];
char command[7];
int via[6];

int getMinIndex()
{
    int min = 99999;
    int minIndex;
    for (int i = 0; i < 6; i++) {
        if (via[i] == 0) {
            if (number[i] < min) {
                min = number[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}

int getMaxIndex()
{
    int max = -99999;
    int maxIndex;
    for (int i = 0; i < 6; i++) {
        if (via[i] == 0) {
            if (number[i] > max) {
                max = number[i];
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}

int main()
{
    for (int i = 0; i < 6; i++) {
        cin >> number[i];
    }

    cin >> command;

    int ret = 0;
    for (int i = 0; i < 6; i++) {
        if (command[i] == 'm') {
            ret = getMinIndex();
        }
        if (command[i] == 'x') {
            ret = getMaxIndex();
        }

        cout << number[ret];
        via[ret] = 1; //다시 선택 못하도록 세팅
    }

    return 0;
}
*/
