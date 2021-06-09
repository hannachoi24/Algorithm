#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, p;
int a[10009];
int able(int x, int si = 0)
{
    int i, j;
    int cnt = 0;
    int k = 0;
    k = a[si];

    for (i = si + 1; i <= n; i++)
    {
        if (a[i] - k > x)
        {
            return -1;
        }

        if (a[i + 1] - k > x)
        {
            cnt++;
            k = a[i];
        }
    }

    if (m - k > x)
        return -1;

    if (cnt <= p)
        return 1;
    return 0;
}

int main()
{
    int i, j, k;
    scanf("%d %d %d", &m, &n, &p);
    a[n + 1] = m;

    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n + 1);

    int l, r, mid;
    l = 0;
    r = 1000000009;

    while (l < r)
    {
        mid = (l + r) / 2;
        int rr = able(mid);

        if (rr == 1)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }

    printf("%d ", l);
    p--;

    for (i = 1; i <= n; i++)
    {
        if (able(l, i) == 1)
            break;
    }

    printf("%d\n", a[i]);
}