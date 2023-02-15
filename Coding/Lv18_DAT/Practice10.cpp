#include <iostream>
using namespace std;

int A[5] = {5, 4, 2, 5, 6};
int B[5] = {5, 7, 5, 4, 2, 9};

int isExist(int n)
{
    for (int i = 0; i < 6; i++)
    {
        if (A[i] == n)
            return 1;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        if (isExist(B[i]))
        {
            cout << "O";
        }
        else
            cout << "X";
    }

    return 0;
}