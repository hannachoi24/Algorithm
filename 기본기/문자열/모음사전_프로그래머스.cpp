#include <string>
#include <vector>

using namespace std;

string aeiou = "AEIOU";
string target = "";
int cnt = -1;
int answer = 0;

void dfs(string word)
{
    cnt++;

    if (word == target)
    {
        answer = cnt;
        return;
    }

    if (word.length() >= 5)
        return;

    for (int i = 0; i < 5; i++)
    {
        dfs(word + aeiou[i]);
    }
}

int solution(string word)
{
    target = word;

    dfs("");

    return answer;
}

/*
1. ""을 시작으로 dfs 수행

2. "AEIOU" 문자열을 순회하면서 dfs 수행

3. dfs 수행할 때마다 cnt++ (사전에서의 단어 위치) ⭐️

4. 현재 단어가 사전에서 몇 번째인지 탐색하려는 단어와 같으면 answer = cnt
*/