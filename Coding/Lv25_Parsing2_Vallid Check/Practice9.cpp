#include <iostream>
#include <string>
using namespace std;

// split

void split(string result[], int &rn, string str, string tar)
{
    str += tar;

    int a = 0;
    int b = 0;

    while (1)
    {
        b = str.find('|', a);
        if (b == -1)
            break;

        string temp = str.substr(a, b - a);

        result[rn++] = temp;

        a = b + 1;
    }
}

int main()
{
    string str = "ID|EWR|DF|WE";

    string result[10];
    int rn = 0;

    split(result, rn, str, "|");

    return 0;
}