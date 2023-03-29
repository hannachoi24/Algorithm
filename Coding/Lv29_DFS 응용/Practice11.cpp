#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int n;
    int weight;
};

vector<vector<Node>> v(4);

int main()
{
    v[0] = {{1, 5}, {3, 8}};
    v[1] = {{2, 6}};
    v[3] = {{1, 7}, {2, 9}};

    return 0;
}