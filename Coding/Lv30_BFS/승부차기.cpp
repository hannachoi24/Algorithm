#include <iostream>
using namespace std;

string str = "ox";
char path[10];
int n;

void run(int level)
{
    if (level == n)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        path[level] = str[i];
        run(level + 1);
        path[level] = 0;
    }
}

int main()
{
    cin >> n;

    run(0);

    return 0;
}