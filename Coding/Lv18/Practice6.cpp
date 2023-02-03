#include <iostream>
#include <cstring>
using namespace std;

// strcmp(A, B) 문자열 0이면 같다고 알려줌

int main()
{
    char arr1[] = "ABC";
    char arr2[] = "ABC";
    if (!strcmp(arr1, arr2))
        cout << "O";
    else
        cout << "X";
}