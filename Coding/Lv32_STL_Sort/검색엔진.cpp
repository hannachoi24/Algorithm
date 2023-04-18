#include <iostream>
using namespace std;

const int N = 6;

int main()
{
    string words[N] = {"ABCD", "ABCE", "AGEH", "EIEI", "FEQE", "ABAD"};

    string input;
    cin >> input;

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (words[i].size() != input.size())
            continue;
        bool match = true;
        for (int j = 0; j < input.size(); j++)
        {
            if (input[j] != '?' && input[j] != words[i][j])
            {
                match = false;
                break;
            }
        }
        if (match == true)
            cnt++;
    }

    cout << cnt;

    return 0;
}