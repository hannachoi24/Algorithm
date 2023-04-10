#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string emails;
    getline(cin, emails);

    vector<string> email_list;
    string email = "";

    for (int i = 0; i < emails.length(); i++)
    {
        if (emails[i] == '|')
        {
            email_list.push_back(email);
            email = "";
        }
        else
        {
            email += emails[i];
        }
    }
    email_list.push_back(email);

    for (int i = 0; i < email_list.size(); i++)
    {
        string email = email_list[i];
        int at_index = email.find('@');
        string name = email.substr(0, at_index);
        string domain = email.substr(at_index + 1);
        int dot_index = domain.find('.');
        if (dot_index != string::npos)
        {
            domain = domain.substr(0, dot_index); // 이메일 안에 .두개 있을 때 처리
        }
        cout << "[#" << name << "] " << domain << "\n";
    }

    return 0;
}