#include <iostream>
#include <string>
using namespace std;

int main()
{
    string id, pass;

    cin >> id >> pass;

    if (id == "BBQ" && pass == "1234")
    {
        cout << "아미고";
    }
    else
        cout << "노노";

    return 0;
}