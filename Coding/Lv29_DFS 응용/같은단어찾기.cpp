#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    string longest_word = "";
    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {
            int k = 0;
            while (i + k < str1.length() && j + k < str2.length() && str1[i + k] == str2[j + k])
            {
                k++;
            }
            if (k > longest_word.length())
            {
                longest_word = str1.substr(i, k);
            }
        }
    }

    cout << longest_word << endl;
    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <cstring>
using namespace std;

char vect1[20] = "ABABCGKABABC";
char vect2[20] = "BTBCKABABCT";
int n1, n2;

int getMaxSize(int a, int b)
{
    int size = 0;
    while (1)
    {
        if (a == n1 || b == n2) break;
        if (vect1[a] != vect2[b]) break;
        a++;
        b++;
        size++;
    }
    return size;
}

int main()
{
    cin >> vect1 >> vect2;

    int a, b;
    n1 = strlen(vect1);
    n2 = strlen(vect2);

    int size;
    int maxSize = 0;
    int maxIndex;

    //a와 b 시작글자위치 선정
    for (b = 0; b < n2; b++) {
        for (a = 0; a < n1; a++) {

            size = getMaxSize(a, b); //a, b 부터 최대 길이 구하기

            if (size > maxSize) {
                maxSize = size;
                maxIndex = a;
            }
        }
    }

    for (int i = 0; i < maxSize; i++) {
        cout << vect1[i + maxIndex];
    }

    return 0;
}
*/