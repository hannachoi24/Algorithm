#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
vector<pair<int, int>> price;
int minNum = 987654321;

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int setPrice, onePrice;
        cin >> setPrice >> onePrice;
        price.push_back({setPrice, onePrice});
        int protein = n / 6;           // 단백질 바를 6개가 들어있는 세트로 구매
        int protein_remainder = n % 6; // 1개 또는 그 이상의 단백질 바를 낱개로 구매
        int sum = protein * setPrice + protein_remainder * onePrice;

        minNum = min(minNum, sum);
    }

    cout << minNum << '\n';
}