#include <iostream>
using namespace std;

void BBQ(int *a, int *b)
{
    int arr[5];
    int max = -99;
    int min = 99;

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];

        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    *a = max;
    *b = min;
}

int main()
{
    int a, b;

    BBQ(&a, &b);

    cout << "a=" << a << '\n';
    cout << "b=" << b << '\n';

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int arr[5];

void BBQ(int a, int b)
{
    a = 0;
    b = 99999;

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > a)
        {
            a = arr[i];
        }
        if (arr[i] < b)
        {
            b = arr[i];
        }
    }
    cout << "a=" << a << '\n';
    cout << "b=" << b << '\n';
}

int main()
{
    int a, b;

    BBQ(a, b);

    return 0;
}
*/