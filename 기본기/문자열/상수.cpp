#include <stdio.h>
#include <iostream>

using namespace std;

int reverse(int num)
{
    int hundred, ten, one, result;
    hundred = num / 100;
    ten = (num / 10) % 10;
    one = num % 10;
    result = one * 100 + ten * 10 + hundred;
    return result;
}

int main(void)
{
    int a, b;
    cin >> a >> b;
    int num1, num2;
    num1 = reverse(a);
    num2 = reverse(b);
    if (num1 > num2)
    {
        cout << num1 << endl;
    }
    else
    {
        cout << num2 << endl;
    }

    return 0;
}