#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[9];

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    int maxValue = -1;

    int maxValueIndex;

    for (int i = 0; i < 9; i++)
    {

        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
            maxValueIndex = i;
        }
    }

    cout << maxValue << '\n'
         << maxValueIndex + 1;
}