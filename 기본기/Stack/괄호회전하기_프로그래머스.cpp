#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        stack<char> st;
        bool flag = false;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                flag = true;
                st.push(s[i]);
            }
            else
            {
                if (s[i] == ']' && st.top() == '[')
                    st.pop();
                if (s[i] == '}' && st.top() == '{')
                    st.pop();
                if (s[i] == ')' && st.top() == '(')
                    st.pop();
            }
        }

        if (st.empty() && flag)
            answer++;

        /* 괄호 회전 과정 */
        char ch = s.front();
        s.erase(s.begin());
        s.push_back(ch);
    }
    return answer;
}

void print(string s, int answer)
{
    int t = solution(s);
}

int main()
{
    print({"[](){}"}, 3);
    print({"}]()[{"}, 2);
    print({"[)()]"}, 0);
    print({"}}}"}, 0);

    return 0;
}