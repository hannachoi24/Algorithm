#include <iostream>
#include <string>
using namespace std;

// erase, insert

int main()
{
    string str = "ABCDEFG";

    str.erase(3, 2); // 3번인덱스 부터 2글자 지우기

    str.insert(1, "<HI>"); // 1번인덱스에 <HI> 넣기

    return 0;
}