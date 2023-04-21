#include <iostream>
using namespace std;

// 보스가 같은지 여부

int myBoss[100];

int getBoss(int n)
{
    if (myBoss[n] == 0)
        return n;

    int ret = getBoss(myBoss[n]);
    myBoss[n] = ret;
    return ret;
}

void setBoss(int t1, int t2)
{
    int a = getBoss(t1);
    int b = getBoss(t2);

    if (a == b)
        return;

    myBoss[b] = a;
}

int main()
{
    freopen_s(new FILE *, "input.txt", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        setBoss(a, b);
    }

    cin >> t;
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        if (getBoss(a) == getBoss(b))
            cout << "O";
        else
            cout << "X";
    }

    return 0;
}