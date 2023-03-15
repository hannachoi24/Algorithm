#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char vect[5][10] = {
        "Jason",
        "Dr.tom",
        "EXEXI",
        "GK12P",
        "POW"};

    char input[10];

    cin >> input;
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(vect[i], input) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        cout << "암호해제";
    else
        cout << "암호틀림";

    return 0;
}

/* #include <iostream>
using namespace std;

char pass[5][7] = {
    "Jason",
    "Dr.tom",
    "EXEXI",
    "GK12P",
    "POW"};

char input;

void isSame()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (pass[i][j] == input)
                return 1;
            if (pass[i][j] != input)
                return 0;
        }
    }
}

int main()
{
    cin >> input;

    if (isSame())
    {
        cout << "암호해제";
    }
    else
    {
        cout << "암호틀림";
    }

    return 0;
}
*/
