#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    str += '_';
    vector<string> words;
    string word;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '_')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += str[i];
        }
    }

    for (int i = 0; i < words.size(); i++)
    {
        cout << i + 1 << "#" << words[i] << "\n";
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string vect[100];
    int t = 0;

    cin >> str;

    string temp;
    int a = 0;
    int b;
    while (1) {
        b = str.find('_', a);
        if (b == -1) {
            b = str.length();
            temp = str.substr(a, b - a);
            if (temp != "") vect[t++] = temp;
            break;
        }

        temp = str.substr(a, b - a);
        if (temp != "") vect[t++] = temp;
        a = b + 1;
    }

    for (int i = 0; i < t; i++) {
        cout << i + 1 << "#" << vect[i] << endl;
    }

    return 0;
}
*/
