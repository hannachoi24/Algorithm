package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 미세먼지안녕 {
    static int R, C, T;
    static int[][] map = new int[50][50];
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static List<Integer> airCleaner = new ArrayList<>();
    static int sumOfDust = 2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                sumOfDust += map[i][j];

                if (map[i][j] == -1) {
                    airCleaner.add(i);
                }
            }
        }

        solution();
    }

    static void solution() {
        while (T-- > 0) {
            // 1. 미세먼지 확산
            map = spreadDust();

            // 2. 공기청정기 가동
            executeAirCleaner();
        }

        System.out.println(totalDust());
    }

    // 1. 미세먼지 확산
    static int[][] spreadDust() {
        int[][] temp = new int[50][50];

        // 확산된 미세먼지를 temp 배열에 계산
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                if (map[x][y] == -1) {
                    temp[x][y] = -1;
                    continue;
                }

                temp[x][y] += map[x][y];

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                        continue;
                    if (map[nx][ny] == -1)
                        continue;

                    temp[nx][ny] += (map[nx][ny] / 5);
                    temp[x][y] -= (map[nx][ny] / 5);
                }
            }
        }

        return temp;
    }

    static void executeAirCleaner() {
        // 위쪽 공기청정기는 반시계 방향
        int top = airCleaner.get(0);

        // 아래로 당기기
        for (int x = top - 1; x > 0; x--) {
            map[x][0] = map[x - 1][0];
        }

        // 왼쪽으로 당기기
        for (int y = 0; y < C - 1; y++) {
            map[0][y] = map[0][y + 1];
        }

        // 위로 당기기
        for (int x = 0; x < top; x++) {
            map[x][C - 1] = map[x + 1][C - 1];
        }

        // 오른쪽으로 당기기
        for (int y = C - 1; y > 1; y--) {
            map[top][y] = map[top][y - 1];
        }

        // 공기청정기에서 부는 바람은 미세먼지가 없는 바람
        map[top][1] = 0;

        // 아래쪽 공기청정기는 시계 방향
        int bottom = airCleaner.get(1);

        // 위로 당기기
        for (int x = bottom + 1; x < R - 1; x++) {
            map[x][0] = map[x + 1][0];
        }

        // 왼쪽으로 당기기
        for (int x = 0; x < C - 1; x++) {
            map[R - 1][x] = map[R - 1][x + 1];
        }

        // 아래로 당기기
        for (int x = R - 1; x > bottom; x--) {
            map[x][C - 1] = map[x - 1][C - 1];
        }

        // 오른쪽으로 당기기
        for (int x = C - 1; x > 1; x--) {
            map[bottom][x] = map[bottom][x - 1];
        }

        // 공기청정기에서 부는 바람은 미세먼지가 없는 바람
        map[bottom][1] = 0;
    }

    static int totalDust() {
        int sum = 2;

        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                sum += map[x][y];
            }
        }

        return sum;
    }
}