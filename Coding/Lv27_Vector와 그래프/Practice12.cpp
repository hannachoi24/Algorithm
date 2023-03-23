#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int n;
    char ch;
};

int main()
{
    vector<Node> vec;

    vec.push_back({1, 'A'});
    vec.push_back({2, 'B'});
    vec.push_back({3, 'C'});
    vec.push_back({4, 'D'});

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        cout << vec[i].n << vec[i].ch << '\n';
    }

    return 0;
}