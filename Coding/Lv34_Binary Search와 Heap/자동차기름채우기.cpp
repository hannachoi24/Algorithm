#include <iostream>
#include <string>

using namespace std;

string str;

int bs(int start, int end)
{
    int max = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (str[mid] == '_')
            end = mid - 1;
        if (str[mid] == '#')
        {
            start = mid + 1;
            if (max < mid)
                max = mid;
        }
    }

    return max;
}

int main()
{
    cin >> str;

    int idx = bs(0, str.length() - 1) + 1;
    int total = str.length();

    cout << idx * 100 / total << "%";

    return 0;
}