#include <iostream>
using namespace std;

int A[6] = {4, 2, 5, 3, 7, 6};
int B[3] = {5, 3, 7};

int main()
{
    int n;
    int flag = 0;
    for (int i = 0; i < 3; i++)
    {
        if (B[i] != A[i + n])
        {
            flag = 1;
            break;
        }
    }

    return 0;
}