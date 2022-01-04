#include <iostream>

using namespace std;

int main()
{
    int N, max = 0;
    int score[1000] = {0};
    double result = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        if (score[i] > max)
        {
            max = score[i];
        }
        result += score[i];
    }

    result = (result / max * 100) / N;

    cout << fixed;
    cout.precision(6);
    cout << result << endl;
}