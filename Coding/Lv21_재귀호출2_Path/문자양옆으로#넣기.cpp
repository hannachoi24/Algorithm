#include <iostream>
using namespace std;

string str;
char ch1, ch2;
bool visited[200] = {
    false,
};

int main()
{
    cin >> str;
    cin >> ch1 >> ch2;

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ch1 || str[i] == ch2)
        {
            if (i == 0)
            {
                visited[i + 1] = true;
            }
            else if (i == len - 1)
            {
                visited[i - 1] = true;
            }
            else
            {
                visited[i - 1] = true;
                visited[i + 1] = true;
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (visited[i])
            cout << '#';
        else
            cout << str[i];
    }

    return 0;
}