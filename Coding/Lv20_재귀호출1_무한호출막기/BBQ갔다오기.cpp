#include <iostream>
using namespace std;

void BBQ(int level)
{
    if (level == 3)
        return;

    BBQ(level + 1);
}

int main()
{
    BBQ(0);

    return 0;
}