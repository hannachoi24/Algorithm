#include <iostream>
#include <list>
using namespace std;

// list라이브러리 활용

list<int> v;

int main()
{
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (auto i = v.begin(); i != v.end(); ++i)
    {
        cout << *i;
    }

    return 0;
}