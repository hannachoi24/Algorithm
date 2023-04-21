#include <iostream>
using namespace std;

// 조직의 수 출력

int myBoss[10];
int groupCnt[10];
int isNew[10];
int totalCnt;
int makeGroupCnt;

int getBoss(int n)
{
    if (myBoss[n] == 0)
        return n;

    int ret = getBoss(myBoss[n]);
    myBoss[n] = ret;
    return ret;
}

void setUnion(int t1, int t2)
{
    // 등장 인물 카운트
    if (isNew[t1] == 0)
    {
        totalCnt++;
        isNew[t1] = 1;
    }

    if (isNew[t2] == 0)
    {
        totalCnt++;
        isNew[t2] = 1;
    }

    int a = getBoss(t1);
    int b = getBoss(t2);

    if (a == b)
        return;

    myBoss[b] = a;

    makeGroupCnt++;
}

int main()
{
    freopen_s(new FILE *, "input3.txt", "r", stdin);

    for (int i = 0; i < 10; i++)
        groupCnt[i] = 1;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        setUnion(a, b);
    }

    cout << totalCnt - makeGroupCnt; // 인원 수 - 그룹 수

    return 0;
}