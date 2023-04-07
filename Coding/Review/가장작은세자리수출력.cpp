#include <iostream>
using namespace std;

int n;
int vect[10];
int history[10];
bool visited[10];

int mini = 21e8; // 21억, 지수표기법

int makeNumber()
{
    int a = history[0];
    int b = history[1];
    int c = history[2];

    return a * 100 + b * 10 + c;
}

void run(int level)
{
    if (level == 3)
    {
        int result = makeNumber();

        if (result < mini && result >= 100)
            mini = result;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            history[level] = vect[i];
            run(level + 1);
            history[level] = 0;
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> vect[i];
    }

    run(0);

    cout << mini;

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> nums;
bool visited[5];
int ans = 999;

void backtrack(int cnt, int curr)
{
    if (cnt == 3)
    {
        if (curr >= 100)
        {
            ans = min(ans, curr);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        backtrack(cnt + 1, curr * 10 + nums[i]); // curr 변수를 10배한 후 새로운 수 더하기
        visited[i] = false;
    }
}

int main()
{
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    backtrack(0, 0);

    cout << ans << endl;
    return 0;
}
*/
