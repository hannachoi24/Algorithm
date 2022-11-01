package 기본기.BackTracking;

import java.util.StringTokenizer;
import java.io.*;

public class N과M2 {
    static int N, M;
    static int[] arr;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];

        dfs(1, 0);

        System.out.println(sb);
    }

    /*
     * start 변수의 의미는 현재 위치, 즉 어디서부터 시작하는지를 의미하는 변수다.
     * 예를들어 반복문에서 재귀를 해줄때, start = 1 부터 시작하면 다음 재귀는 오름차순으로 탐색하기 위해 start을 1 증가시킨 2를
     * 인자로 넘겨주면서 다음 재귀의 반복문이 2부터 시작하도록 하는 변수를 의미
     */
    public static void dfs(int start, int depth) {
        /*
         * 깊이가 M이랑 같을경우 출력하고 빠져나옴
         */

        if (depth == M) {
            for (int val : arr) {
                sb.append(val).append(' ');
            }
            sb.append('\n');
            return;
        }

        /*
         * i는 start부터 탐색하도록 한다.
         */
        for (int i = start; i <= N; i++) {
            arr[depth] = i; // 현재 깊이를 index로 하여 해당 위치에 i 값을 담는다

            /*
             * 재귀호출
             * 현재 i 값보다 다음 재귀에서 더 커야하므로
             * i + 1 의 값을 넘겨주고, 깊이 또한 1 증가시켜 재귀호출 해준다
             */
            dfs(i + 1, depth + 1);
        }
    }
}
