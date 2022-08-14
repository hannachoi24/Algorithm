package 그래프;

import java.io.*;
import java.util.*;

public class 연결요소의개수 {
    static int N; // 정점 개수
    static int M; // 간선 개수
    static int[][] adj; // 인접행렬
    static boolean[] visit; // 방문 체크

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new int[N + 1][N + 1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a][b] = 1;
            adj[b][a] = 1;
        }

        visit = new boolean[N + 1];

        int count = 0; // 연결요소 개수

        // 방문 배열 돌면서 방문하지 않은 정점이 있으면 탐색하고 연결요소 개수 1 증가
        for (int i = 1; i < N + 1; i++) {
            if (!visit[i]) {
                dfs(i);
                count++;
            }
        }

        System.out.println(count);
    }

    public static void dfs(int start) {
        visit[start] = true;

        // 방문 배열 처음부터 돌면서 간선이 연결되어 있고, 방문을 하지 않았으면 dfs 탐색
        for (int i = 1; i < N + 1; i++) {
            if (adj[start][i] == 1 && !visit[i]) {
                dfs(i);
            }
        }
    }
}
