#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> bombs(n);

    for (int i = 0; i < n; i++)
    {
        cin >> bombs[i];
    }

    vector<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push_back(bombs[i]);
        int size = st.size();
        if (size >= 3 && st[size - 1] == st[size - 2] && st[size - 2] == st[size - 3])
        {
            st.pop_back();
            st.pop_back();
            st.pop_back();
        }
    }

    sort(st.begin(), st.end());

    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i] << " ";
    }

    return 0;
}