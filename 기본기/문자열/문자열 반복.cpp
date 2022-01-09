#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int r;      // 문자열 반복 횟수
        string str; // 문자열
        cin >> r;
        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            for (int k = 0; k < r; k++)
            {
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }
}