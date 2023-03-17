#include <iostream>
#include <string>
using namespace std;

// 대괄호 안에 있는 문자열 출력

// 같은 작업을 반복하는거면 함수로 빼는 게 좋음
string go(string str)
{
    if (str.find('[') == -1)
        return "";
    int a = str.find('[');
    int b = str.find(']');

    int size = b - a - 1;
    string result = str.substr(a + 1, size);

    return result;
}

int main()
{
    string str[4] = {
        "ABCQ",
        "B[4]R",
        "CCDA",
        "BT[15]"};

    for (int i = 0; i < 4; i++)
    {
        cout << go(str[i]) << " ";
    }

    return 0;
}