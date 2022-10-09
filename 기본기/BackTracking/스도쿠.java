package 기본기.BackTracking;

import java.io.*;
import java.util.*;

public class 스도쿠 {
    static int[][] arr = new int[9][9];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < 9; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        sudoku(0, 0);

    }

    public static void sudoku(int row, int col) {

        // 해당 행이 다 채워졌을 경우 다음 행의 첫 번째 열부터 시작
        if (col == 9) {
            sudoku(row + 1, 0);
            return;
        }

        // 행과 열이 모두 채워졌을 경우 출력 후 종료
        if (row == 9) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    sb.append(arr[i][j]).append(' ');
                }
                sb.append('\n');
            }
            System.out.println(sb);
            // 출력 뒤 시스템을 종료한다.
            System.exit(0);
        }

        // 만약 해당 위치의 값이 0 이라면 1부터 9까지 중 가능한 수 탐색
        if (arr[row][col] == 0) {
            for (int i = 1; i <= 9; i++) {
                // i 값이 중복되지 않는지 검사
                if (possibility(row, col, i)) {
                    arr[row][col] = i; // 중복되지 않으므로 값 넣어주고
                    sudoku(row, col + 1); // 지귀 호출
                }
            }
            arr[row][col] = 0;
            return;
        }

        sudoku(row, col + 1);

    }

    public static boolean possibility(int row, int col, int value) {

        // 같은 행에 있는 원소들 중 겹치는 열 원소가 있는지 검사
        for (int i = 0; i < 9; i++) {
            if (arr[row][i] == value) {
                return false;
            }
        }

        // 같은 열에 있는 원소들 중 겹치는 행 원소가 있는지 검사
        for (int i = 0; i < 9; i++) {
            if (arr[i][col] == value) {
                return false;
            }
        }

        // 3*3 칸에 중복되는 원소가 있는지 검사
        int set_row = (row / 3) * 3; // value가 속한 3x3의 행의 첫 위치
        int set_col = (col / 3) * 3; // value가 속한 3x3의 열의 첫 위치

        for (int i = set_row; i < set_row + 3; i++) {
            for (int j = set_col; j < set_col + 3; j++) {
                if (arr[i][j] == value) {
                    return false;
                }
            }
        }

        return true; // 중복되는 것이 없을 경우 true 반환
    }
}

/*
 * <문제>
 * 정수값이 같은 행과 열에 겹치지 않으면서 3×3 행렬 안에서도 겹치면 안된다.
 * -> 재귀호출부와 조건 검사 함수, 이렇게 두 개를 구성하도록 하자.
 * 
 * <풀이>
 * 빈칸은 0 으로 주어진다. 2차원 배열을 활용
 * 즉, int[][] 배열을 사용 할 것인데, 첫 번째 인덱스는 행을, 두 번째 인덱스는 열을 의미한다. (int arr[row][col])
 * 그리고 [0][0]을 왼쪽 위를 기준으로 시작
 * 
 * [조건식]
 * 스도쿠 규칙은 간단하다. 해당 칸에 속한 3×3 배열 안에서 숫자가 겹치지 않으며, 해당 칸과 같은 행과 열 또한 숫자가 겹치지 않아야
 * 한다. 즉, 어떤 값이 해당 칸에 들어갈 수 있는지 여부를 판별해야된다. 이때 탐색하려는 값을 value 라고 정하고 조건식을 만들면 세
 * 가지 조건식을 만들 수 있다.
 * 
 * (0, 0)부터 검사!
 * 1. 같은 행에 있는 열 원소 중에 겹치는 수가 있는지를 검사한다.
 * 2. 같은 열에 있는 행 원소 중에 겹치는 수가 있는지를 검사한다.
 * 3. 해당 위치에 속한 3×3 칸에 중복되는 수가 있는지를 검사한다.
 * -> 3×3의 위치는 9×9 사이즈에서 3개로 나누면 총 9칸이 생기는데, 각 칸의 위치는 왼쪽 위를 기준으로 할 것이기 때문에 나눗셈을
 * 통해
 * 나머지를 버린 뒤 다시 3을 곱하여 0, 3, 6 중 하나가 나올 수 있도록 한다. 즉, 9개의 칸의 첫 원소의 위치는 다음 9개 중
 * 하나다.
 * ([0][0], [0][3], [0][6], [3][0], [3][3], [3][6], [6][0], [6][3], [6][6])
 * 
 * => 위 3가지 조건을 모두 통과해야 해당 value값이 해당 칸에 수가 될 수 있게 된다.
 * 그리고 배열을 (0,0) 부터 순회하며 만약 탐색하는 칸의 값이 0(빈칸)일 경우 반복문을 통해 1 ~ 9 까지의 수들 중 위의
 * possibility 함수를 통해 만족하게 된다면 재귀호출을 해주는 것이다.
 * 
 * => 재귀 호출하면서 모든 값이 다 채워지게 된다면 배열을 출력한 뒤 시스템을 종료해야한다. 아니면 여러개의 스도쿠가 출력된다.
 * (문제에서 나와있듯이 경우의 수가 많을 경우 '한 개'만 출력하라고 명시되어있다.)
 * 이 때 시스템을 종료하는 방법은 System.exit(0)를 사용하면 된다.
 */