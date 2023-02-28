#include <iostream>
#include <string>
using namespace std;

struct MC
{
    string burger1;
    string burger2;
};

int main()
{
    MC bob;
    MC tom;

    cin >> bob.burger1;
    cin >> bob.burger2;
    cin >> tom.burger1;
    cin >> tom.burger2;

    cout << "bob.burger1=" << bob.burger1.length() << '\n';
    cout << "bob.burger2=" << bob.burger2.length() << '\n';
    cout << "tom.burger1=" << tom.burger1.length() << '\n';
    cout << "tom.burger2=" << tom.burger2.length() << '\n';

    return 0;
}