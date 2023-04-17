#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[11][11];
int n;

vector<int> rSelect;
int sn;
int sDat[10];

void init()
{
    cin >> n;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> map[y][x];
        }
    }

    int bit;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> bit;

            if (bit == 1)
            {
                rSelect.push_back(map[y][x]);
                sDat[map[y][x]]++; // dat 처리
            }
        }
    }

    sn = rSelect.size();
}

bool compare(int a, int b)
{
    if (sDat[a] > sDat[b])
        return true;
    if (sDat[a] < sDat[b])
        return false;
    return a < b;
}

int main()
{
    init();

    sort(rSelect.begin(), rSelect.end(), compare);

    for (int i = 0; i < sn; i++)
    {
        cout << rSelect[i] << " ";
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n * n);
    for (int i = 0; i < n * n; i++) {
        cin >> numbers[i];
    }

    vector<vector<int>> bits(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bits[i][j];
        }
    }

    vector<int> extractedNumbers;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bits[i][j] == 1) {
                extractedNumbers.push_back(numbers[i * n + j]);
            }
        }
    }

    map<int, int> freq;
    for (int num : extractedNumbers) {
        freq[num]++;
    }

    vector<pair<int, int>> freqVec(freq.begin(), freq.end());
    sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for (auto p : freqVec) {
        int num = p.first;
        int count = p.second;
        for (int i = 0; i < count; i++) {
            cout << num << " ";
        }
    }

    return 0;
}
*/