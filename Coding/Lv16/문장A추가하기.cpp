#include <iostream>
#include <string>

using namespace std;

int main()
{
    string arr, tmp;
    int idx;

    cin >> arr;
    cin >> idx;

    tmp = "";

    string A = arr.substr(0, idx);
    string B = "A";
    string C = arr.substr(idx);

    tmp += arr.substr(0, idx) + "A" + arr.substr(idx);

    cout << tmp;

    return 0;
}