package 그래프;

import java.io.*;
import java.util.*;

public class 친구 {
    static int n;
    static int[][] map;
    static final int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        map = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                if (line.charAt(j - 1) == 'Y') {
                    map[i][j] = 1;
                } else {
                    map[i][j] = INF;
                }
            }
        }
        floydWarshall();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                if (map[i][j] <= 2) {
                    cnt++;
                }
            }
            ans = Math.max(ans, cnt);
        }
        System.out.println(ans);
    }

    static void floydWarshall() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j || j == k || k == i)
                        continue;
                    map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }
    }

}
