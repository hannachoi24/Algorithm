#include <iostream>
#include <vector>
using namespace std;

vector<int> v = {4, 5, 6, 1, 1, 3, 2, 6, 9, 1, 1, 2, 0, 3, 2};

int isSeven(int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += v[i];
    }

    int limit = v.size() - size;
    for (int i = 0; i <= limit; i++)
    {
        if (sum == 7)
            return 1;

        sum -= v[i];
        sum += v[i + size];
    }
    return 0;
}

void go()
{
    for (int i = v.size(); i >= 0; i--)
    {
        int ret = isSeven(i);
        if (ret == 1)
        {
            cout << i;
            return;
        }
    }
    cout << "없음";
}

int main()
{
    go();

    return 0;
}