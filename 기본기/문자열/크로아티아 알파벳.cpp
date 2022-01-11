#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<string> str = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int index = 0;
    string S;
    cin >> S;
    for (int i = 0; i < str.size(); i++)
    {
        index = S.find(str[i]);
        for (; index != string::npos; index = S.find(str[i]))
            S.replace(index, str[i].length(), "@");
    }
    cout << S.length();
}

/*
string.find("") 함수는 파라미터로 받은 문자열이 string에 포함되어 있는지 확인하는 함수이다.

문자열이 존재한다면 해당 문자열이 시작되는 처음 위치를 리턴한다.

문자열이 존재하지 않는다면 string::npos를 리턴한다.

 
크로아티아 알파벳이 있는지 확인한 뒤, 

그 입력받은 문자열의 시작 위치부터 길이만큼 잘라내기를 생각했다.

하지만 잘라냈을 경우 for 문에서의 문제도 생기고,

앞의 문자와 뒤의 문자가 합쳐지면서 크로아티아 알파벳이 완성되면 안 되기 때문에  string.replace() 함수를 사용하여 문자열을 전혀 상관없는 특수문자로 대체했다.

 

string.replace() 함수의 각 파라미터 뜻은 string.replace(문자열의 시작 위치, 문자열의 길이, 대체 문자)이다.

replace 함수가 문자열 길이에 제약받지 않으므로 @ 하나로 대체한 뒤,

최종적으로 문자열 길이를 구하게 되면 일반 알파벳들 개수 + 대체된 크로아티아 알파벳(@) 개수가 된다.
*/