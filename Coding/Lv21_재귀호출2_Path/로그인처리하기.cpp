#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char id[10];
    char password[10];
    cin >> id >> password;

    if (!strcmp(id, "qlqlaqkq") && !strcmp(password, "tkaruqtkf"))
    {

        cout << "LOGIN";
    }
    else
    {
        cout << "INVALID";
    }

    return 0;
}