#include <iostream>
using namespace std;

int a, b;

void run(int level)
{
    cout << level << " ";
    if (level == b)
        return;
    run(level + 1);
    cout << level << " ";
}

int main()
{
    cin >> a >> b;
    run(a);
    return 0;
}