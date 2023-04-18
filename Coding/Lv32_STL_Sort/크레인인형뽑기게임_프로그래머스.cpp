#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> st;

    for (int i = 0; i < moves.size(); i++)
    {
        int col = moves[i] - 1;

        for (int row = 0; row < board.size(); row++)
        {
            if (board[row][col] != 0)
            {
                if (!st.empty() && st.top() == board[row][col])
                {
                    st.pop();
                    answer += 2;
                }
                else
                    st.push(board[row][col]);
                board[row][col] = 0;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    int ret = solution(board, moves);

    if (ret == 4)
        cout << "정답";
    else
        cout << "오답";
}

/*
1. moves에 있는 것들을 다 체크해야함 근데 1부터 시작이므로 col = moves[i] - 1

2. x축으로 들어가야 하므로 col[row][moves]를 row를 증가하면서 0이 아닌것을 체크

3. 0이 아닌 경우

3 - 1 스택의 top과 넣어야 하는 인형이 같은 경우 넣지 않고 그냥 pop, 2개 사라졌으므로 answer +=2

3 - 2 스택의 top과 다른 경우 그냥 push

4. 해당 좌표의 인형을 0으로 없애주고 더 깊이 안들어가므로 break
*/