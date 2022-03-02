#include <iostream>
using namespace std;

int gcd(int a, int b) // 최대공약수
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

int lcm(int a, int b) // 최소공배수
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b);

    return 0;
}
