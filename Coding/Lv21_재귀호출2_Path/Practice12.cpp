#include <iostream>
using namespace std;

char path[3]; // 한번에 출력하기 위해 char형으로
// char arr[5] = "ABCD";

void run(int lev)
{
    if (lev == 2)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = 'A' + i;
        // path[lev] = arr[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    run(0);

    return 0;
}