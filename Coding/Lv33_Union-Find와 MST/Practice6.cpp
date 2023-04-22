#include <iostream>
using namespace std;

// 사이클 여부 판단

int myBoss[200];

int find(int n)
{
    if (myBoss[n] == 0)
        return n;

    int ret = find(myBoss[n]);
    myBoss[n] = ret;
    return ret;
}

void setUnion(int t1, int t2)
{
    int a = find(t1);
    int b = find(t2);

    if (a == b)
        return;

    myBoss[b] = a;
}

int main()
{
    freopen_s(new FILE *, "input4.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char a, b;
        cin >> a >> b;

        if (find(a) == find(b))
        {
            cout << "Cycle 발견\n";
            return 0;
        }

        setUnion(a, b);
    }

    return 0;
}