#include <cstdio>

using namespace std;

int main()
{
    int n, num[100], sum = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%1d", &num[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += num[i];
    }

    printf("%d\n", sum);
}