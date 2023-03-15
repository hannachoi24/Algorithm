#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[4][10];

    for (int i = 0; i < 4; i++)
    {
        cin >> str[i];
    }

    int max = -99;
    int min = 99;

    int maxIndex;
    int minIndex;

    for (int i = 0; i < 4; i++)
    {
        int len = strlen(str[i]);

        if (max < len)
        {
            max = len;
            maxIndex = i;
        }

        if (min > len)
        {
            min = len;
            minIndex = i;
        }
    }

    cout << "긴문장:" << maxIndex << '\n';
    cout << "짧은문장:" << minIndex << '\n';
}

/* 또 다른 코드
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1[4];

    string max = "";
    string min = "aaaaaaaaaaaaaaaaaa";

    int posA = 0;
    int posB = 0;

    for (int i = 0; i < 4; i++)
    {

        cin >> s1[i];

        if (s1[i].size() > max.size())
        {
            max = s1[i];
            posA = i;
        }

        if (s1[i].size() < min.size())
        {
            min = s1[i];
            posB = i;
        }
    }

    cout << "긴문장:" << posA << '\n';
    cout << "짧은문장:" << posB << '\n';

    return 0;
}
*/