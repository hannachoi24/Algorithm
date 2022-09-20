package 그래프;

import java.util.*;

public class 로봇청소기 {
    static int N, M, cnt = 0; // N: 세로, M: 가로, cnt: 청소 영역 개수
    static int map[][], visited[][];

    public static void main(String[] args) {
        int r, c, d; // (r, c)좌표, d:방향

        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        r = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt(); // 0 북, 1 동, 2 남, 3 서

        map = new int[N][M];
        visited = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        cnt++;
        dfs(r, c, d);

        System.out.println(cnt);
    }

    static int[] dx = { -1, 0, 1, 0 }; // 북, 동, 남, 서
    static int[] dy = { 0, 1, 0, -1 };

    public static void dfs(int x, int y, int dir) {
        int nx, ny, cant = 0;

        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            dir = dir - 1 < 0 ? 3 : dir - 1;
            nx = x + dx[dir];
            ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            } else if (map[nx][ny] == 0 && visited[nx][ny] == 0) {
                dfs(nx, ny, dir);
                cnt++;
                break;
            }
            cant++;
        }

        // 2-3, 2-4인 경우
        x = x - dx[dir];
        y = y - dy[dir];
        if (x < 0 || x >= N || y < 0 || y >= M) {
            return;
        } else if (cant == 4 && map[x][y] == 0) {
            dfs(x, y, dir);
        }
    }// dfs
}