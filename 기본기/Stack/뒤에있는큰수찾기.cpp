#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    stack<int> st;

    for (int i = 0; i < numbers.size(); i++)
    {
        while (!st.empty() && numbers[st.top()] < numbers[i])
        {
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }

    return answer;
}

/*
1. 우선, answer를 주어진 numbers의 size 크기로 설정하고 모두 -1로 초기화해 줍니다.

2. pair<int, int>형 stack을 선언해 줍니다.

3. 스택이 비어있지 않은 경우 스택의 top에 있는 숫자와 현재 숫자를 비교합니다. 현재 숫자가 더 클 경우 문제에서 주어진 조건인 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 충족하므로 answer[top에 위치한 숫자의 인덱스] = 현재 숫자로 설정해 준 뒤 스택을 pop 합니다.

3.1 스택이 비어있거나 스택의 다음 top의 숫자가 현재 숫자 이상일 경우 조건 미충족이므로 4번 과정으로 넘어갑니다.

4. 스택에 { 현재 숫자, 인덱스 }를 넣어줍니다.

5. 3 ~ 4번 과정을 numbers 내 모든 숫자에 대해 진행해 준 뒤 answer를 반환합니다.
*/