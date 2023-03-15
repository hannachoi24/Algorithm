#include <iostream>
#include <cstring>
using namespace std;

// 세 문장 입력 받고 같은 문장인지 구현

int main()
{
    char word1[10] = {0};
    char word2[10] = {0};
    char word3[10] = {0};

    cin >> word1;
    cin >> word2;
    cin >> word3;

    int compare1 = strcmp(word1, word2);
    int compare2 = strcmp(word1, word3);
    int compare3 = strcmp(word3, word1);

    if (compare1 && compare2 && compare3)
    {
        cout << "BAD"; // 세 문장 모두 다르면
    }
    else if (compare1 || compare2 || compare3)
    {
        cout << "GOOD"; // 두 문장만 같으면
    }
    else if (!compare1 && !compare2 && !compare3)
        cout << "WOW"; // 세 문장 모두 같으면

    return 0;
}
