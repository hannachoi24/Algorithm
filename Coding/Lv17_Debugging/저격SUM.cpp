#include <iostream>
using namespace std;

int arr[11] = {3, 4, 1, 1, 2, 6, 8, 7, 8, 9, 10};

int getSum(int index)
{
    int sum = 0;
    for (int i = index; i < index + 5; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int startIndex;
    int result;
    cin >> startIndex;

    result = getSum(startIndex);

    cout << result;

    return 0;
}