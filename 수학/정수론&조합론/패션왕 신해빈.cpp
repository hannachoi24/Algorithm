#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 최악의 경우는 의상이 30개에 모든 의상의 종류가 다를 경우이며 경우의 수는 2^30-1으로 int형의 범위를 넘어서지 않는다. 
조합의 수는 만약 상의 x2, 하의 x2, 신발 x2 인 경우에는 (2+1)*(2+1)*(2+1) - 1 = 26이며 아무것도 안 입는 경우인 1을 빼주어야 한다. */

int N, T;
int ans;
vector<pair<string, int>> v; // <의상 이름, 의상 수>
string s1, s2;

int main()
{
    cin >> T; // 테스트케이스 수

    while (T--)
    {
        ans = 1;
        cin >> N; // 의상 수

        for (int i = 0; i < N; i++)
        {
            cin >> s1 >> s2;

            if (v.size() == 0) // 맨 처음 값 벡터에 저장 후 1개 체크
            {
                v.push_back({s2, 1});
                continue;
            }

            for (int j = 0; j < (int)v.size(); j++)
            {
                if (s2 == v[j].first)
                {
                    v[j].second++; // 개수 체크
                    break;
                }
                if (j == (int)v.size() - 1)
                    v.push_back({s2, 0}); // vector에 있지않은 원소라면 추가.
            }
        }
        for (int k = 0; k < (int)v.size(); k++) // 가능한 조합 수 구하기
            ans *= (v[k].second + 1);

        cout << ans - 1 << "\n"; // 아무것도 안입는 경우인 1 빼기

        v.clear(); // 벡터 비우기
    }
}