#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, T;
int ans;
string s1, s2;

int main()
{
    cin >> T; // 테스트케이스 수

    while (T--)
    {
        map<string, int> m; // Map<의상종류,의상수>

        ans = 1;
        cin >> N; // 의상 수

        for (int i = 0; i < N; i++)
        {
            cin >> s1 >> s2;

            // 해당key값이 존재하지 않을 경우 find함수는 end()리턴
            if (m.find(s2) == m.end())
            {
                m[s2] = 1;
            }
            else // 해당 key값이 존재할 경우
            {
                m[s2]++;
            }
        }

        for (auto iter : m)           // iter.first = key, iter.second = value
            ans *= (iter.second + 1); // (의상수+1) 씩 곱하기

        cout << ans - 1 << "\n"; // 아무것도 안입는 경우인 1 빼기
    }
}