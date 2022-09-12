package 완전탐색;

import java.util.*;
import java.io.*;

public class 꽃길 {
    static int n;
    static int map[][];
    static int dx[] = { 0, 0, 0, -1, 1 }; // 원점을 포함한 5개의 지점(원점, 상, 하, 좌, 우)
    static int dy[] = { 0, -1, 1, 0, 0 };
    static boolean visit[][];
    static int result = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visit = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken()); // 화단의 지점당 가격 입력 받기
            }
        }

        dfs(0, 0);

        System.out.println(result);

    }

    // 4방향 방문체크 초기화
    public static void checkVisit(int x, int y, Boolean flag) {
        for (int k = 0; k <= 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            visit[nx][ny] = flag;
        }
    }

    public static void dfs(int level, int sum) {
        // 꽃을 3개 심었을 경우(모두 꽃이 피게)
        if (level == 3) {
            sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (visit[i][j])
                        sum += map[i][j];
                }
            }

            result = Math.min(result, sum);
            return;
        }

        // 아직 3개 다 못 심었으면
        for (int x = 1; x < n - 1; x++) {
            for (int y = 1; y < n - 1; y++) {
                if (!visit[x][y]) {
                    boolean flag = false;
                    for (int i = 1; i <= 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 0 | nx >= n || ny < 0 || ny >= n || visit[nx][ny] == true) {
                            flag = false;
                            break;
                        }

                        flag = true;
                    }

                    if (flag) {
                        checkVisit(x, y, flag);
                        dfs(level + 1, sum + map[x][y]);
                        checkVisit(x, y, !flag);
                    }
                }
            }
        }
    }
}
