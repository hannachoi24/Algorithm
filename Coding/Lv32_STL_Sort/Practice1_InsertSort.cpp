#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {4, 2, 3, 1, 5};

    int result[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        // 1. 맨 뒤에 넣기
        result[i] = arr[i];

        // 2. 정렬 수행
        for (int j = i; j > 0; j--)
        {
            if (result[j - 1] > result[j])
            {
                swap(result[j - 1], result[j]);
            }
            else
                break; // 내 자리
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}