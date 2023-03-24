#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v; // 원소 하나하나가 배열 형태

int main()
{
    v.push_back({});
    v.push_back({});

    v[0].push_back(3);
    v[0].push_back(5);

    return 0;
}