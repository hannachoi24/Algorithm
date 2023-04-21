#include <iostream>
using namespace std;

// Union-Find
// 같은 그룹인지

int myBoss[10];

int getBoss(int n)
{
    if (myBoss[n] == 0) // 최종 보스
    {
        return n;
    }

    int ret = getBoss(myBoss[n]);
    myBoss[n] = ret; // 깊이 -> 너비 형태로 변경 (성능을 위한 경로 압축 코드)
    return ret;
}

void setBoss(int t1, int t2)
{
    int a = getBoss(t1); // t1의 보스 찾음
    int b = getBoss(t2); // t2의 보스 찾음

    if (a == b) // 보스가 같으면 종료
        return;

    myBoss[b] = a; // b아래 a가 들어감 -> b가 보스
}

int main()
{
    setBoss(6, 7);
    setBoss(5, 6);
    setBoss(1, 2);

    if (getBoss(5) == getBoss(6))
    {
        cout << "같은 그룹\n";
    }
    else
    {
        cout << "다른 그룹";
    }

    return 0;
}