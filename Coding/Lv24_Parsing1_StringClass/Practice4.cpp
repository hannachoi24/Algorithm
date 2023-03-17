#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "BADGDDGDGDKFCSSSS";

    int ret = str.find("KFC", 5); // 인덱스 5부터 찾아라

    cout << ret;

    return 0;
}