#include <iostream>
using namespace std;

int vect[8];
int bucket[10];

int main()
{
    for (int i = 0; i < 8; i++)
    {
        cin >> vect[i];
    }

    for (int i = 0; i < 8; i++)
    {
        bucket[vect[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < bucket[i]; j++)
        {
            cout << i << " ";
        }
    }

    return 0;
}