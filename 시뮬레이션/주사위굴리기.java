package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//   1
// 2 3 4
//   5
//   6

public class 주사위굴리기 {
    static int N, M, x, y; // N(열): 지도 세로 크기, M(행): 지도 가로 크기, x,y: 주사위를 놓은 곳의 좌표, K: 명령어 개수
    static int[][] map;
    static int[] dx = { 1, -1, 0, 0 }; // 동 서 북 남
    static int[] dy = { 0, 0, -1, 1 };
    static int[] dice = new int[7]; // 방향 배열

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken()); // 열
        x = Integer.parseInt(st.nextToken()); // 행
        int K = Integer.parseInt(st.nextToken());

        map = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            int d = Integer.parseInt(st.nextToken());
            move(d);
        }
    }

    static void move(int d) {
        int nx = x + dx[d - 1];
        int ny = y + dy[d - 1];

        if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1)
            return;
        roll(d, nx, ny);
        x = nx;
        y = ny;
    }

    // 1 2 3 4 (동 서 북 남)
    static void roll(int d, int x, int y) {
        int tmp = dice[3];
        switch (d) {
            case 1:
                dice[3] = dice[4];
                dice[4] = dice[6];
                dice[6] = dice[2];
                dice[2] = tmp;
                break;

            case 2:
                dice[3] = dice[2];
                dice[2] = dice[6];
                dice[6] = dice[4];
                dice[4] = tmp;
                break;

            case 3:
                dice[3] = dice[5];
                dice[5] = dice[6];
                dice[6] = dice[1];
                dice[1] = tmp;
                break;

            case 4:
                dice[3] = dice[1];
                dice[1] = dice[6];
                dice[6] = dice[5];
                dice[5] = tmp;
                break;

        }

        if (map[y][x] == 0) {
            map[y][x] = dice[6];
        } else {
            dice[6] = map[y][x];
            map[y][x] = 0;
        }
        System.out.println(dice[3]);
    }
}
