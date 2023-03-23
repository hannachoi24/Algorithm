#include <iostream>
#include <vector>
using namespace std;

// 인접행렬

string name = "ABSTR";
vector<vector<int>> arr(5);

int main()
{
    for (int i = 0; i < 5; i++)
    {
        arr[i] = {0, 0, 0, 0, 0};
    }

    arr[0][1] = 1;
    arr[0][3] = 1;
    arr[1][3] = 1;
    arr[1][4] = 1;
    arr[2][4] = 1;
    arr[3][1] = 1;

    return 0;
}