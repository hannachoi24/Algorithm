#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end(), greater<char>());
    // sort 함수를 쓰면 기본적으로 오름차순 정렬이 되지만 greater<type>()을 마지막에 추가하게 되면 내림차순으로 정렬하게 된다.
    cout << str;
}