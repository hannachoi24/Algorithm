#include <iostream>
#include <string>

using namespace std;

int main()
{

    string arr;

    for (int i = 0; i < 3; i++)
    {
        cin >> arr;
    }

    if (arr.find("M"))
    {
        cout << "M이 존재합니다" << '\n';
    }
    else if (arr.find("M") == std::string::npos)
    {

        cout << "M이 존재하지 않습니다" << '\n';
    }

    return 0;
}