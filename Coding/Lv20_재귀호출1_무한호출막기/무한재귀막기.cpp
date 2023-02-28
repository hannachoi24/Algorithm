#include <iostream>
using namespace std;

void bbq(int level)
{
    if (level == 4)
    {
        return;
    }

    bbq(level + 1);
}

int main()
{
    bbq(0);

    return 0;
}