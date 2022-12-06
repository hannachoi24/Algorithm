package 시뮬레이션;

import java.io.*;
import java.util.*;

public class Easy_2048 {
    private static int n;
    private static int[][] map;
    private static int[][] temp;
    private static int[] direct;
    private static boolean[][] visit;

    private static int max = 0;

    private static int[] dx = { -1, 0, 1, 0 };// 상우하좌
    private static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(reader.readLine());

        map = new int[n + 1][n + 1];
        direct = new int[5];

        StringTokenizer st;
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(reader.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(5, 0);// 5번
        System.out.println(max);

    }

    private static void dfs(int end, int index) {

        if (index == end) {

            // 확인
            confirm();

        } else {
            for (int i = 0; i < 4; i++) {
                direct[index] = i;
                dfs(end, index + 1);
            }
        }

    }// dfs

    private static void confirm() {

        temp = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            temp[i] = map[i].clone();
        }

        for (int d = 0; d < direct.length; d++) {
            visit = new boolean[n + 1][n + 1];

            if (direct[d] == 0) {// 상
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        move(i, j, direct[d]);
                    }
                }
            } else if (direct[d] == 2) {// 하
                for (int i = n; i >= 1; i--) {
                    for (int j = 1; j <= n; j++) {
                        move(i, j, direct[d]);
                    }
                }
            } else if (direct[d] == 1) {// 우
                for (int i = n; i >= 1; i--) {
                    for (int j = 1; j <= n; j++) {
                        // 오른쪽부터 봐야함 (j,i로 보내기)
                        move(j, i, direct[d]);
                    }
                }
            } else {// 좌
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        // 왼쪽부터 봐야함
                        move(j, i, direct[d]);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (temp[i][j] > max) {
                    max = temp[i][j];
                }
            }
        }

    }// confirm

    private static void move(int x, int y, int dir) {
        // 빈칸이면 종료
        if (temp[x][y] == 0) {
            return;
        }

        while (true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 1 || ny < 1 || nx > n || ny > n) {
                return;
            }
            if (visit[nx][ny]) {
                return;
            }
            if (temp[nx][ny] == temp[x][y]) {
                // 같은 값일 때 합치기
                visit[nx][ny] = true;
                temp[nx][ny] *= 2;
                temp[x][y] = 0; // 합쳤으면 원래 자리는 0(빈칸)으로 변경
                return;
            } else if (temp[nx][ny] != 0) {
                // 같지 않고 다른 수가 있을 때 못합침
                return;
            }

            // 위 경우에 모두 해당하지 않으면 값을 이동시키고, 이동 전 배열 값을 0으로 만듬
            temp[nx][ny] = temp[x][y];
            temp[x][y] = 0;
            x = nx;
            y = ny;

        }
    }// move
}

/*
 * 총 5번 이동이 가능하기 때문에 방향 조합을 dfs로 해결한다.
 * 0~3방향을 크기가 5인 dir배열에 모든 경우의 수를 담음으로써 모든 경우를 탐색할 수 있다.
 * 기존 배열을 그대로 사용할 수 없으니 계산을 위한 배열(temp)을 만들어 기존 배열을 복사한다.
 */