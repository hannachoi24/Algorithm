package 기본기.BackTracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class nQueen {
    public static int[] arr;
    public static int N; // 체스판의 크기
    public static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N];

        Queen(0);
        System.out.println(count);
    }

    public static void Queen(int depth) {
        // 모든 원소(행)를 다 채운 상태면 count 증가 및 return
        if (depth == N) {
            count++;
            return;
        }

        for (int i = 0; i < N; i++) {
            // arr[depth] -> 인덱스는 열을 나타내고 값은 칸이 됨
            arr[depth] = i; // 첫 번째 열에 '행'의 값을 찾고, 두 번째 열에 또 다른 행의 값을 찾으며 나아가는 과정
            // 놓을 수 있는 위치일 경우 재귀호출
            // Posibility(): 해당 열에서 i번째 행에 놓을 수 있는지를 검사하는 함수(가지 치기)
            if (Possibility(depth)) {
                Queen(depth + 1);
            }
        }
    }
    /*
     * 즉, 재귀탐색을 하게되면 기본적으로 '행'은 서로 다른 위치이니 우리가 검사할 것은 다른 퀸과 동일한
     * '열'에 위치하는지와 대각선상에 위치하는지를 검사하면 된다.
     * 만약 해당 위치가 공격받지 않는 위치라면 다음 재귀를 호출하고, 아닐경우는 다음 반복문으로 넘어간다.
     */

    public static boolean Possibility(int col) { // col은 새로 놓는 퀸(이미 유망한 바로 앞에 퀸과 새로놓는 퀸을 비교)

        /* 세로방향으로 놓여있는 경우 */
        for (int i = 0; i < col; i++) {
            // 새로 놓은 퀸의 열이 앞에 있는 퀸의 열과 같으면 (같은 열에 존재할 경우)
            if (arr[col] == arr[i]) {
                return false;
            }

            /*
             * 대각선상에 놓여있는 경우
             * (열의 차와 행의 차가 같을 경우가 대각선에 놓여있는 경우다) -> 피타고라스 삼각형 생각해보기(dx, dy)
             * 배열의 값은 '열', index(위치)는 '행'
             */

            else if (Math.abs(col - i) == Math.abs(arr[col] - arr[i])) { // col - i: dy, arr[col] - arr[i]: dx
                return false;
            }

        }

        return true;
    }
}
