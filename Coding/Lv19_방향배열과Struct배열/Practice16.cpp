#include <iostream>
using namespace std;

struct Node
{
    int a, b;
};

Node vect[3][4] = {
    {{1, 2}, {5, 3}, {1, 4}, {1, 5}},
    {{1, 1}, {1, 1}, {1, 1}, {1, 2}},
    {{1, 4}, {1, 5}, {2, 2}, {3, 3}},

};

int directX[4] = {-1, 0, 1, 0};
int directY[4] = {0, 1, 0, -1};

int getDirect(int x, int y)
{

    int sum = 0;
    int mul = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + directX[i];
        int ny = y + directY[i];

        if (nx < 0 || nx >= 3 || ny < 0 || ny >= 4)
            continue;

        sum += vect[nx][ny].a;
        mul *= vect[nx][ny].b;
    }

    return sum + mul;
}

int main()
{
    cout << getDirect(1, 1);

    return 0;
}
