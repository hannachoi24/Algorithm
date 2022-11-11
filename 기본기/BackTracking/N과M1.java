package 기본기.BackTracking;

import java.io.*;
import java.util.*;

public class N과M1 {
    static int[] arr; // 결과를 담을 배열
    static boolean[] visit; // 중복체크를 위한 방문 배열
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        arr = new int[M];
        visit = new boolean[N];

        dfs(N, M, 0);

        System.out.println(sb);
    }

    public static void dfs(int N, int M, int depth) {
        if (depth == M) {
            for (int val : arr) {
                sb.append(val).append(' ');
            }
            sb.append('\n');
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!visit[i]) {
                visit[i] = true;
                arr[depth] = i + 1; // 해당 깊이를 index로 하여 i + 1 값 저장
                dfs(N, M, depth + 1); // 다음 자식 노드 방문을 위해 depth 1 증가시키면서 재귀호출
                visit[i] = false;
            }
        }
    }
}
