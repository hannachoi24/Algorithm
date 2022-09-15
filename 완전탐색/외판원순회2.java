package 완전탐색;

import java.io.*;
import java.util.*;

public class 외판원순회2 {
    static int n, min, w[][];
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        w = new int[n][n];
        visit = new boolean[n];
        min = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                w[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            dfs(i, i, 0, 0);
        }

        System.out.println(min);
    }

    static void dfs(int start, int i, int cnt, int sum) {
        if (cnt == n && start == i) {
            min = Math.min(min, sum);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (w[i][j] == 0)
                continue;

            if (!visit[i] && w[i][j] > 0) {
                visit[i] = true;
                sum += w[i][j];
                dfs(start, j, cnt + 1, sum);
                sum -= w[i][j];
                visit[i] = false;
            }
        }
    }
}
