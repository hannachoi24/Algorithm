#include <iostream>
#include <string>
using namespace std;

string str[5];

int main()
{
    int pos = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> str[i];

        if (str[i] == "up")
            pos++;

        else
            pos--;
    }

    if (pos >= 0)
    {
        cout << pos + 1;
    }

    else
    {
        cout << "B" << -(pos);
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char vect[5][5];

    for (int i = 0; i < 5; i++) {
        cin >> vect[i];
    }

    int loc = 0;

    for (int i = 0; i < 5; i++) {
        if (strcmp(vect[i], "up") == 0) loc++;
        if (strcmp(vect[i], "down") == 0) loc--;
    }

    if (loc >= 0) cout << loc + 1;
    else  cout << "B" << -loc;

    return 0;
}
*/