#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/* string 벡터를 선언하고, string의 비교 조건을 str.length() 순으로, 만약 같을 경우엔 사전순으로 비교하게끔 하는 compare 함수를 만들어서 
sort함수로 정렬하면 풀이가 가능하다.
또한, 출력부에서 만약 동일한값이 이미 출력됐을경우엔 출력하지 않도록 설정해주면 풀이가 가능하다.
STL Sort를 사용하되, compare함수를 얼마나 자유자재로 사용할 수 있는가를 묻는 문제인 듯하다.
compare함수를 필요에 맞게 바꾸는 연습을 하고 넘어가도록 하자. */

bool compare(string a, string b)
{
    int i = 0;
    if (a.length() == b.length()) // 길이가 같으면 사전순으로
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                return a[i] < b[i];
            }
        }
    }
    return a.length() < b.length();
}

int main()
{
    int n;
    string tmp;
    cin >> n;
    vector<string> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), compare);

    cout << arr[0] << '\n';

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i]) // 동일한값이 이미 출력됐을경우엔 출력하지 않도록
            continue;
        cout << arr[i] << '\n';
    }
}
