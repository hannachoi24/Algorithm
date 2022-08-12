package 그래프;

import java.util.*;

public class 미친로봇 {
    static int n;
    static int dx[] = { -1, 1, 0, 0 };
    static int dy[] = { 0, 0, -1, 1 };
    static boolean visit[][];
    static double percent[];
    static double result;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        percent = new double[4];
        visit = new boolean[30][30]; // 시작점을 15, 15로 잡기 위함.
        /*
         * N의 최대값은 15이다. 그러므로 시작지점을 15, 15로 잡고 최소 좌표값을 0, 0
         * 최대 좌표값을 30, 30으로 설정해주었다.
         */

        for (int i = 0; i < 4; i++) {
            percent[i] = sc.nextInt() * 0.01;
        }
        sc.close();

        result = 0;

        dfs(15, 15, 0, n, 1);

        System.out.println(result);
    }

    public static void dfs(int x, int y, int idx, int n, double total) {
        if (idx == n) {
            result += total;
            return;
        }

        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 30 && ny >= 0 && ny < 30) {
                if (visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    dfs(nx, ny, idx + 1, n, total * percent[i]); // 해당 방향으로 이동할 때 그 방향의 확률을 곱해주고 N번 이동이 끝나면 그 값을 결과값에
                                                                 // 더해주면 된다.
                    visit[nx][ny] = false;
                }
            }
        }
    }
}
