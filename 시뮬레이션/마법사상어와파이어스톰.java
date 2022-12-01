package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 마법사상어와파이어스톰 {
    static int N, Q;
    static int[][] map;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static int result, totalIce;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        N = (int) Math.pow(2, N);
        map = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        int[] L = new int[Q];
        for (int i = 0; i < Q; i++) {
            L[i] = Integer.parseInt(st.nextToken());
        }

        // Q번 파이어스톰 시전
        for (int i = 0; i < Q; i++) {
            map = divide(L[i]); // 회전
            map = melt(); // 얼음 녹이기
        }

        result = totalIce = 0;

        biggest();

        System.out.println(totalIce);
        System.out.println(result);
    }

    // 부분격자별로 90도 회전
    public static int[][] divide(int L) {
        int[][] tmp = new int[N][N];
        L = (int) Math.pow(2, L);
        for (int i = 0; i < N; i += L) {
            for (int j = 0; j < N; j += L) {
                rotate(i, j, L, tmp);
            }
        }
        return tmp;
    }

    // 90도 회전
    public static void rotate(int x, int y, int L, int[][] tmp) {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                tmp[x + i][y + j] = map[x + L - 1 - j][y + i];
            }
        }
    }

    // 특정칸에 인접해 있는 얼음칸이 3개 미만이면 그 특정칸 얼음 녹임
    public static int[][] melt() {
        int[][] tmp = new int[N][N];
        for (int i = 0; i < N; i++) {
            tmp[i] = Arrays.copyOf(map[i], N);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int cnt = 0; // 얼음칸 개수 카운트
                if (map[i][j] == 0) {
                    continue;
                }
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if (map[nx][ny] > 0) {
                            cnt++;
                        }
                    }
                }

                if (cnt < 3) {
                    tmp[i][j]--;
                }

            }
        }
        return tmp;
    }

    // 남아있는 얼음의 합과 가장 큰 덩어리가 차지하는 칸의 개수
    public static void biggest() {
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visit = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                totalIce += map[i][j];
                if (map[i][j] > 0 && !visit[i][j]) {
                    q.add(new int[] { i, j });
                    visit[i][j] = true;
                    int cnt = 1;

                    while (!q.isEmpty()) {
                        int[] t = q.poll();
                        int tx = t[0];
                        int ty = t[1];

                        for (int d = 0; d < 4; d++) {
                            int nx = tx + dx[d];
                            int ny = ty + dy[d];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                                if (map[nx][ny] > 0 && !visit[nx][ny]) {
                                    visit[nx][ny] = true;
                                    q.add(new int[] { nx, ny });
                                    cnt++;
                                }
                            }
                        }
                    }
                    result = Math.max(result, cnt);
                }
            }
        }
    }
}