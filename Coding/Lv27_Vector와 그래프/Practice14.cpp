#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int a, b;
};

vector<Node> arr = {{1, 2}, {3, 4}};

int main()
{
    auto i = 43;
    auto v = 'A';

    vector<int> vec = {3, 5, 7, 8};

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        cout << *i << " "; // i에는 주소가 들어가 있음
    }

    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout << i->a << " " << i->b << '\n';
    }

    return 0;
}