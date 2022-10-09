package 그래프;

import java.io.*;
import java.util.*;

public class 알파벳 {
    static int R, C;
    static int[][] board;
    static int dx[] = { -1, 1, 0, 0 };
    static int dy[] = { 0, 0, -1, 1 };
    static boolean[] visit;
    static int max = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new int[R][C];
        visit = new boolean[26];

        for (int i = 0; i < R; i++) {
            String[] str = br.readLine().split("");
            for (int j = 0; j < C; j++) {
                String alpha = str[j];
                board[i][j] = alpha.charAt(0) - 'A'; // 알파벳을 int형으로 변환하여 board에 저장
            }
        }

        dfs(0, 0, 0);
        System.out.println(max);
    }

    static void dfs(int x, int y, int cnt) {
        if (visit[board[x][y]]) {
            max = Math.max(max, cnt);
            return;
        } else {
            visit[board[x][y]] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1)
                    continue;
                dfs(nx, ny, cnt + 1);
            }

            visit[board[x][y]] = false;

        }
    }
}
