#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    char ch;

    cin >> n >> ch;

    vector<char> vec(n + 1);

    char c = ch;
    for (int i = 0; i < 5; i++)
    {
        vec[n - i] = c;
        c++;
    }

    c = ch;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(c);
        c++;
    }

    return 0;
}