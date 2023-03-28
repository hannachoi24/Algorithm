#include <iostream>
#include <vector>
using namespace std;

// vector형태로 넘기고 값 바꿨을 때

// 방법1
void bts(vector<int> &v)
{
    v[0] = 100;
}

int main()
{
    vector<int> m = {1, 2, 3};

    bts(m);

    return 0;
}

// 방법2
vector<int> bts(vector<int> v)
{
    v[0] = 100;

    return v;
}

int main()
{
    vector<int> m = {1, 2, 3};

    vector<int> ret = bts(m);

    return 0;
}