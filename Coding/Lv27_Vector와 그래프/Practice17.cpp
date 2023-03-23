#include <iostream>
#include <vector>
using namespace std;

// 바껴서 출력 됨

vector<int> vec(vector<int> arr)
{
    arr[0] = 999;

    return arr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    arr = vec(arr);

    return 0;
}