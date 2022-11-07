package 기본기.BackTracking;

import java.io.*;
import java.util.*;

public class N과M3 {
    static int N, M;
    static int[] arr;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];
        dfs(0);
        System.out.println(sb);
    }

    public static void dfs(int depth) {
        /*
         * 깊이가 최대 깊이일경우
         * 더이상 탐색할 자식노드는 없으므로 return해준다.
         */
        if (depth == M) {
            for (int val : arr) {
                sb.append(val).append(' ');
            }
            sb.append('\n');
            return;
        }

        /*
         * 깊이를 1씩 증가시키면서 DFS를
         * 재귀호출한다.
         */
        for (int i = 1; i <= N; i++) {
            // 만약 추가 조건이 있다면 반복문 안에 추가하면 된다.
            arr[depth] = i;
            dfs(depth + 1);
        }
    }
}
