#include <iostream>
using namespace std;

void run(int x, int depth)
{
    // cout << x << " ";
    if (depth == 4)
    {
        return;
    }

    run(x + 2, depth + 1);
    cout << x << " ";
}

int main()
{
    int n;
    cin >> n;
    run(n, 0);

    return 0;
}

/* 또 다른 코드
규칙: n칸씩 k번 재귀를 돌아야 한다면.. n * (k + 1) == level
#include <iostream>
using namespace std;

int n;
void run(int level)
{
    if (level == n + 8) return;
    run(level + 2);
    cout << level << " ";
}

int main()
{
    cin >> n;
    run(n);
    return 0;
}
*/