#include <iostream>
using namespace std;

int gcd(int a, int b)
{

    int n;

    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b, T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
}