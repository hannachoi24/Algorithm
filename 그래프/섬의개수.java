package 그래프;

import java.io.*;
import java.util.*;

public class 섬의개수 {
    static int w;
    static int h;
    static int[][] map;
    static int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
    static int dy[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static boolean[][] visit; // 방문 체크
    static int count = 0; // 섬 개수

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

            map = new int[h][w];

            visit = new boolean[h][w];

            count = 0;

            if (w == 0 && h == 0)
                break;

            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (map[i][j] == 1 && !visit[i][j]) {
                        visit[i][j] = true;
                        dfs(i, j);
                        count++;
                    }
                }
            }

            System.out.println(count);

        }
    }

    static void dfs(int x, int y) {

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (map[nx][ny] == 1 && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    dfs(nx, ny);
                }
            }
        }
    }
}