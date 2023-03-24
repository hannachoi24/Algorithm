#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A[3][3] = {
        2, 6, 3,
        7, 1, 1,
        3, 4, 2};

    int B[2][4] = {
        6, 4, 2, 4,
        1, 1, 5, 8};

    int C[2][3] = {
        9, 2, 3,
        4, 2, 1};

    int candidates[8];
    int idx = 0;

    // A 배열에서 가장 큰 값 3개 선택
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            candidates[idx++] = A[i][j]; // 값이 들어가는 것과 동시에 idx증가
        }
    }
    sort(candidates, candidates + 9, greater<int>()); // greater<int>(): 내림차순 정렬
    cout << candidates[0] << " " << candidates[1] << " " << candidates[2] << '\n';

    idx = 0;
    // B 배열에서 가장 작은 값 3개 선택
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            candidates[idx++] = B[i][j];
        }
    }
    sort(candidates, candidates + 8);
    cout << candidates[0] << " " << candidates[1] << " " << candidates[2] << '\n';

    idx = 0;
    // C 배열에서 가장 작은 값 2개와 가장 큰 값 1개 선택
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            candidates[idx++] = C[i][j];
        }
    }
    sort(candidates, candidates + 6);
    cout << candidates[0] << " " << candidates[1] << " " << candidates[5] << '\n';

    return 0;
}