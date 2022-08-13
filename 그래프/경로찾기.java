package 그래프;

import java.io.*;
import java.util.StringTokenizer;

/*
플로이드 와샬이란 모든 정점에서 모든 정점으로의 최단 경로를 구하는 알고리즘이다.
플로이드 와샬의 핵심 아이디어는 '거쳐 가는 정점'을 기준으로 최단 거리를 구하는 것이다.
즉 i에서 j까지 가는 것과 i에서 k로 가고 k에서 j로 가는 것은 같다는 의미이다.
*/

public class 경로찾기 {
    static int n;
    static int[][] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());

        adj = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                adj[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // i에서 j까지 갈 수 있는가?
        // i에서 k로 가고, k에서 j로 갈 수 있는가?
        for (int k = 0; k < n; k++) { // 거쳐갈 노드
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // 단순히 갈 수 있는 경로가 있는지만 체크
                    if (adj[i][k] == 1 && adj[k][j] == 1) {
                        adj[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(adj[i][j] + " ");
            }
            System.out.println();
        }
    }
}
