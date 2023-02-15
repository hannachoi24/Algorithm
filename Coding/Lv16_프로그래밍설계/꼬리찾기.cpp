#include <iostream>
#include <string>
using namespace std;

int main()
{

    string answer = "";

    for (int i = 0; i < 3; i++)
    {
        string arr;
        cin >> arr;
        answer += arr.back();
    }

    cout << answer;
    return 0;
}
