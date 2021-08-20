#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

int main()
{

    while (1)
    {
        getline(cin, str); // 공백까지 입력받아야 하므로
        stack<char> s;
        if (str[0] == '.')
            break;

        for (int i = 0; i < str.length() - 1; i++)
        {
            if (str[i] == '(')
                s.push('(');
            if (str[i] == '[')
                s.push('[');
            if (str[i] == ']')
            {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else
                {
                    cout << "no" << endl;
                    break;
                }
            }

            if (str[i] == ')')
            {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else
                {
                    cout << "no" << endl;
                    break;
                }
            }

            if (s.empty() && i == str.length() - 2)
                cout << "yes" << endl; // str[str.length() - 1] = '.' 이므로 검사할 필요가 없다.
            else if (!s.empty() && i == str.length() - 2)
                cout << "no" << endl;
        }
    }
}