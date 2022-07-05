package 완전탐색;

import java.util.Scanner;

public class nQueen {
    public static int[] arr;
    public static int N; // 체스판의 크기
    public static int count = 0;

    @SuppressWarnings("resource")
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextInt();
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
            // Posibility(): 해당 열에서 i번째 행에 놓을 수 있는지를 검사하는 함수
            if (Possibility(depth)) {
                Queen(depth + 1);
            }
        }
    }
    /*
     * 즉, 재귀탐색을 하게되면 기본적으로 '열'은 서로 다른 위치이니 우리가 검사할 것은 다른 퀸과 동일한
     * '행'에 위치하는지와 대각선상에 위치하는지를 검사하면 된다.
     * 만약 해당 위치가 공격받지 않는 위치라면 다음 재귀를 호출하고, 아닐경우는 다음 반복문으로 넘어간다.
     */

    public static boolean Possibility(int col) {

        for (int i = 0; i < col; i++) {
            // 해당 열의 행과 i열의 행이 일치할 경우 (같은 행에 존재할 경우)
            if (arr[col] == arr[i]) {
                return false;
            }

            /*
             * 대각선상에 놓여있는 경우
             * (열의 차와 행의 차가 같을 경우가 대각선에 놓여있는 경우다)
             * index(위치)는 '열' 해당 인덱스의 값은 '행'이라고 생각
             */

            else if (Math.abs(col - i) == Math.abs(arr[col] - arr[i])) {
                return false;
            }

        }

        return true;
    }

}
