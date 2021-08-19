#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    int num;
    int sum = 0;
    stack<int> s;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> num;
        if (num == 0)
        {
            s.pop();
        }
        else
        {
            s.push(num);
        }
    }
    for (int i = 0; !s.empty(); i++)
    {
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;

    return 0;
}
