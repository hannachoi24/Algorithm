#include <iostream>
#include <vector>

using namespace std;

long long sum(std::vector<int> &a)
{
    long long result = 0;
    for (vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
        result += *iter;

    /*<방법2>
        for (int i = 0 i < a.size(); i++)
        {
            result = result + a[i];
        }*/

    return result;
}
