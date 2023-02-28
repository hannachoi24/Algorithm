#include <iostream>
using namespace std;

void run(int x)
{
    cout << x << " ";
    if (x == 0)
    {
        return;
    }

    run(x - 1);

    cout << x << " ";
}

int main()
{
    int n;
    cin >> n;
    run(n);
}