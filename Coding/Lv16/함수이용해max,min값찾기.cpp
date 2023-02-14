#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str = "";

int maxIndex()
{
    int max = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] > str[max])
        {
            max = i;
        }
    }

    return max;
}

int minIndex()
{
    int min = 0;
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] < str[min])
        {
            min = j;
        }
    }

    return min;
}

int main()
{

    cin >> str;

    cout << maxIndex() << endl;
    cout << minIndex();

    return 0;
}