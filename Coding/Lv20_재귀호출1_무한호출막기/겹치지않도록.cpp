#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr1(4, vector<int>(4));
    vector<vector<int>> arr2(4, vector<int>(4));

    // 첫 번째 비트배열 입력 받기
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr1[i][j];
        }
    }

    // 두 번째 비트배열 입력 받기
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr2[i][j];
        }
    }

    // 비트단위로 AND 연산하여 겹치는 부분이 있는지 확인
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr1[i][j] == 1 && arr2[i][j] == 1)
            {
                flag = true;
                break;
            }
        }
    }

    // 결과 출력
    if (flag)
    {
        cout << "걸리다" << '\n';
    }
    else
    {
        cout << "걸리지않는다" << '\n';
    }

    return 0;
}
