#include <iostream>

using namespace std;

int main()
{
    int A[4];
    int B[4];
    int result[4] = {0};
    /*
1 2 3 4 
5 6 7 8
*/
    for (int i = 0; i < 4; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < 4; i++)
    {
        result[i] = A[i] + B[3 - i];
    }

    for (int i = 0; i < 4; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}