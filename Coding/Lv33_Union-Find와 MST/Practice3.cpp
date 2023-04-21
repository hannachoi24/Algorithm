#include <iostream>
using namespace std;

// 1, 2, 9번 사람이 소속된 사람 수 출력
// 정답: 4 2 4

int myBoss[10];
int groupCnt[10];

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
    int a = getBoss(t1);
    int b = getBoss(t2);

    if (a == b)
        return;

    myBoss[b] = a;

    groupCnt[a] += groupCnt[b];
    groupCnt[b] = 0;
}

int getCount(int n)
{
    int t = getBoss(n);
    return groupCnt[t];
}

int main()
{
    freopen_s(new FILE *, "input2.txt", "r", stdin);

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

    cin >> t;
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        cout << getCount(a) << " ";
    }

    return 0;
}