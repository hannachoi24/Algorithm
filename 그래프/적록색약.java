package 그래프;

import java.util.Scanner;

/*
1. 데이터입력받을 때 1줄씩 받고, charAt 을 통해 한글자씩 잘라서 map[][] 배열에 저장해준다.

2. 색약이 아닌 사람의 경우와 색약인 사람의 경우를 나눠서 2번 DFS를 돌려준다. 

3. 색약인 사람의 경우에는 녹색과 적색을 구분 못하므로, G를 R로 모두 바꿔준 후에 DFS를 돌린다.

4. visits[][] 배열은 두번째 돌리기 전에 초기화를 시켜줘야 된다.  
*/

public class 적록색약 {
    static int n;
    static String s;
    static char[][] map;
    static boolean[][] visit;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        map = new char[n + 1][n + 1];
        visit = new boolean[n + 1][n + 1];

        for (int i = 0; i < n; i++) {
            s = sc.next();
            for (int j = 0; j < n; j++) {
                map[i][j] = s.charAt(j); // R R R B B
            }
        }

        // normal인 경우
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        int normal_cnt = cnt;
        cnt = 0;
        visit = new boolean[n + 1][n + 1];

        // dltonism 인 경우
        // G를 R로 바꿔주고 돌린다.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 'G')
                    map[i][j] = 'R'; // G를 R로 바꿔준다.
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        int abnormal_cnt = cnt;

        System.out.println(normal_cnt + " " + abnormal_cnt);
    }

    public static void dfs(int x, int y) {
        visit[x][y] = true;
        char tmp_char = map[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > n || ny < 0 || ny > n)
                continue;

            if (!visit[nx][ny] && map[nx][ny] == tmp_char) {
                dfs(nx, ny);
            }
        }
    }
}
