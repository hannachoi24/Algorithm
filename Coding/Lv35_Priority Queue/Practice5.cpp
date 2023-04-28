#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int n;
    int price;
};

vector<vector<int>> alist(6);

int main()
{
    alist[0] = {{1, 15}, {3, 30}};
    alist[1] = {{2, 5}};
    alist[2] = {{4, 2}, {3, 10}};
    alist[3] = {{5, 7}};
    alist[3] = {{5, 1}};

    return 0;
}
