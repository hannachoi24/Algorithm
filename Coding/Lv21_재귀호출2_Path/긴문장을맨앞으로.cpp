#include <iostream>
#include <string>
using namespace std;

string word[3];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> word[i];
    }

    int idx = -1;
    int maxLength = -1;

    for (int i = 0; i < 3; i++)
    {
        int len = word[i].length();
        if (len > maxLength)
        {
            idx = i;
            maxLength = word[i].length();
        }
    }

    swap(word[0], word[idx]);

    for (int i = 0; i < 3; i++)
    {
        cout << word[i] << '\n';
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char vect[3][11];
    int len;
    int max;
    int maxIndex;

    //세 문장 입력
    for (int i = 0; i < 3; i++)
    {
        cin >> vect[i];
    }

    //가장 긴 문장 찾기
    max = -1;
    for (int i = 0; i < 3; i++)
    {
        len = strlen(vect[i]);
        if (max < len)
        {
            max = len;
            maxIndex = i;
        }
    }

    //swap(vect[maxIndex], vect[0]);
    char temp[11];

    strcpy(temp, vect[maxIndex]);
    strcpy(vect[maxIndex], vect[0]);
    strcpy(vect[0], temp);


    //출력
    for (int i = 0; i < 3; i++)
    {
        cout << vect[i] << endl;
    }

    return 0;
}
*/
