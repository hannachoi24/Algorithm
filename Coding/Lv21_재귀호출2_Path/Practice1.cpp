#include <iostream>
using namespace std;

void run(int level)
{
    if (level == 4)
    {
        return;
    }

    void(level + 1);
    cout << "#";
}

int main()
{
    run(0);

    return 0;
}