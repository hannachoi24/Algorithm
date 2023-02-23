#include <iostream>
using namespace std;

struct Data
{
    int x;
    int y;
    int z;
};

int main()
{
    struct Data a, b;

    cin >> a.x >> a.y >> a.z;
    cin >> b.x >> b.y >> b.z;

    cout << a.x + b.x;
    cout << a.y + b.y;
    cout << a.z + b.z;

    return 0;
}
