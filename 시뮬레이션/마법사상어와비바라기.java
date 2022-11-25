package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 마법사상어와비바라기 {
    static int N, M;
    static int[][] map;
    static boolean[][] visit;
    static int[][] wind;
    static int[] dx = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }; // 좌부터 시계방향
    static int[] dy = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
    static ArrayList<Air> list;
    static int d, s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        wind = new int[M][2]; // 이동 정보 저장 배열

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            wind[i][0] = Integer.parseInt(st.nextToken()); // d
            wind[i][1] = Integer.parseInt(st.nextToken()); // s
        }

        list = new ArrayList<Air>();
        list.add(new Air(N - 2, 0));
        list.add(new Air(N - 1, 0));
        list.add(new Air(N - 2, 1));
        list.add(new Air(N - 1, 1));

        for (int i = 0; i < M; i++) {
            visit = new boolean[N][N];
            int d = wind[i][0];
            int s = wind[i][1];
            move(d, s);
            add();
            remove();
        }

        System.out.println(amount());
    }

    private static int amount() {
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result += map[i][j];
            }
        }
        return result;
    }

    private static void remove() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] >= 2 && !visit[i][j]) {
                    map[i][j] -= 2;
                    list.add(new Air(i, j));
                }
            }
        }
    }

    private static void add() {
        for (Air air : list) {
            int cnt = 0;
            int nx = -1;
            int ny = -1;

            for (int i = 2; i <= 8; i += 2) {
                nx = air.x + dx[i];
                ny = air.y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] > 0) {
                    cnt++;
                }
            }
            map[air.x][air.y] += cnt;
        }
        list.clear(); // 비를 나중에 뿌려줘야 하기 때문에 구름을 바로 삭제하지 않고 비를 뿌려준 후에 삭제
    }

    private static void move(int d, int s) {
        for (Air air : list) {
            int nx = (air.x + N + dx[d] * s % N) % N;
            int ny = (air.y + N + dy[d] * s % N) % N;

            visit[nx][ny] = true;
            map[nx][ny] += 1;
            air.x = nx;
            air.y = ny;
        }
    }

    static class Air {
        int x, y;

        public Air(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
