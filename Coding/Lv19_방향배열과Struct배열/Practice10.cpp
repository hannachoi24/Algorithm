#include <iostream>
using namespace std;

int main()
{
    char buf[10] = "ABC";
    char tt[10] = "KFC";
    char temp[10];

    // swap
    strcpy(temp, buf);
    strcpy(buf, tt);
    strcpy(tt, temp);

    strcat(buf, "KKKK"); // 뒤에 붙여줌

    return 0;
}