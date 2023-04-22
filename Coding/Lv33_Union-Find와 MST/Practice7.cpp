#include <iostream>
using namespace std;

// kruskal(MST)

int myBoss[200];

struct Node
{
    char a;
    char b;
    int price;
};

Node list[100];

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
    freopen_s(new FILE *, "input6.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Node temp;

        cin >> temp.a >> temp.b >> temp.price;

        list[i] = temp; // 복사
    }

    // 1. sort;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (list[i].price > list[j].price)
            {
                swap(list[i], list[j]);
            }
        }
    }

    int sum = 0;
    // 채택

    int cnt = 0;
    for (i = 0; i < n; i++)
    {
        int a = list[i].a;
        int b = list[i].b;
        int price = list[i].price;

        if (find(a) == find(b))
            continue;
        setUnion(a, b);
        cnt++;
        sum += price;
        if (cnt == 4)
            break;
    }

    cout << sum;

    return 0;
}