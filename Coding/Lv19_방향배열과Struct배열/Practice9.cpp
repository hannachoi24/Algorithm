#include <iostream>
using namespace std;

int main()
{
    char buf[10] = "ABC";
    char temp[10];

    strcpy(temp, buf);

    cout << temp;

    return 0;
}