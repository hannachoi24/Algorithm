#include <iostream>
#include <string>
using namespace std;

int main()
{
    char buf[10] = "QWE"; // C언어 스타일의 문자열 -> C++ String
    string bts = buf;

    // 반대로 C++스타일의 string -> C언어 스타일의 char 변환

    strcpy(buf, bts.c_str());

    printf("%s", bts.c_str());

    return 0;
}