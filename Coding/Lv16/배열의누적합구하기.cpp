#include <iostream>

using namespace std;

int main()
{
    int A[6];

    for (int i = 0; i < 6; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i < 6; i++)
    {
        A[i] = A[i] + A[i - 1];
    }

    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}