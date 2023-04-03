#include <iostream>
using namespace std;

int arr[3][3] = {
    0, 12, 0,
    9, 0, 3,
    0, 6, 0};

void turn()
{
    int temp = arr[1][0];
    arr[1][0] = arr[2][1];
    arr[2][1] = arr[1][2];
    arr[1][2] = arr[0][1];
    arr[0][1] = temp;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n / 90; i++)
    {
        turn();
    }

    cout << arr[0][1] << " ";
    cout << arr[1][0] << " ";
    cout << arr[1][2] << " ";
    cout << arr[2][1] << endl;

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    // 시계에 있는 숫자들을 벡터에 저장합니다.
    vector<int> nums = {12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // 회전시킨 결과를 저장할 벡터를 만듭니다.
    vector<int> rotated(12);

    // 각 숫자가 회전한 후의 위치를 계산하여 rotated 벡터에 저장합니다.
    for (int i = 0; i < 12; i++) {
        int new_idx = (i + k / 30) % 12;
        rotated[new_idx] = nums[i];
    }

    // 결과를 출력합니다.
    cout << rotated[0] << " " << rotated[9] << " " << rotated[3] << " " << rotated[6] << endl;

    return 0;
}
*/