#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int sum = a + b;

    vector<int> vec(sum);
    // vector<int> vec(a+b, a*b); 이 방법도 있음

    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = a * b;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }

    return 0;
}
