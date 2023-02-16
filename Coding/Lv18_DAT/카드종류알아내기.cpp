#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char CardList[12];
    cin >> CardList;
    int len = strlen(CardList);
    int dat[200] = {0};

    for (int i = 0; i < len; i++)
    {
        dat[CardList[i]]++;
    }

    int cnt = 0;
    for (int k = 0; k < 200; k++)
    {
        if (dat[k] >= 1)
        {
            cnt++;
        }
    }

    cout << cnt << "개";

    return 0;
}

/* 또 다른 정답 코드
int main() {
    char cardList[20] = { 0 };
    int bucket[100] = { 0 };
    int len;

    cin >> cardList;


    for (int i = 0; i < 20; i++)
    {
        if (cardList[i] == '\0')
        {
            len = i;
            break;
        }
    }

    for (int i = 0; i < len; i++)
    {
        bucket[cardList[i]]++;
    }

    int count = 0;
    for (int i = 65; i < 100; i++)
    {
        if (bucket[i] > 0) count++;
    }

    cout << count << "개";

    return 0;
}
*/
