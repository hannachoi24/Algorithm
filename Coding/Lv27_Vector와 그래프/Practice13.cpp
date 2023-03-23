#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    char ch1;
    char ch2;
};

int main()
{
    int n;
    cin >> n;

    vector<Node> vec;

    for (int i = 0; i < n; i++)
    {
        char ch1, ch2;
        cin >> ch1 >> ch2;
        vec.push_back({ch1, ch2});
    }

    swap(vec[0], vec[vec.size() - 1]);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i].ch1 << " " << vec[i].ch2 << '\n';
    }

    return 0;
}