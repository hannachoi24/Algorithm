#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Cmp(int A, int B)
{
    if (A > B)
        return true;
    else
        return false;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());      // 오름 차순 정렬
    sort(B.begin(), B.end(), Cmp); // 내림 차순 정렬

    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int value = A[i] * B[i]; // 곱한 값이 최소가 되기 위해서는, 큰 숫자 일 수록 작은 숫자와 곱해야 상대적으로 더 작은값이 나옴
        sum = sum + value;
    }
    return sum;
}