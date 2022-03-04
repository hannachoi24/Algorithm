#include <iostream>
#include <stack>
using namespace std;

bool vps(string ps)
{
    stack<char> s;
    bool sw = true;

    for (int i = 0; i < ps.size(); i++)
    {
        if (ps[i] == '(')
        {
            s.push(ps[i]);
        }
        else if (!s.empty() && ps[i] == ')')
        {
            s.pop();
        }
        else if (s.empty() && ps[i] == ')')
        {
            sw = false;
            break;
        }
    }

    if (s.empty() && sw)
        return true;
    else
        return false;
}

int main()
{
    string ps;
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> ps;

        if (vps(ps))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

// 먼저 왼쪽 괄호는 스택에 삽입
// 오른쪽 괄호는 괄호의 짝이 맞는지 확인하기 위해 사용된다.
// )를 만났는데 스택이 비어 있다면 왼쪽 괄호가 없다는 뜻이므로 잘못된 괄호
// 비어있지 않다면 짝이 있으므로 하나 씩 pop
// 모든 괄호를 연산한 후, 스택이 아직 남아있다면 왼쪽 괄호와 오른쪽 괄호의 짝이 맞지 않으므로 잘못된 괄호
// 모든 연산 후, 스택이 비어 있다면 괄호의 짝이 맞았다는 뜻이므로 true를 리턴