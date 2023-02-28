#include <iostream>
using namespace std;

void run(int level)
{
    if (level == 0)
        return;

    run(level / 2);

    cout << level << " ";
}

int main()
{
    int n;
    cin >> n;

    run(n);

    return 0;
}