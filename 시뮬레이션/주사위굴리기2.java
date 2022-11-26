package 시뮬레이션;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 주사위굴리기2 {
    static int N, M, K, total, cur_x, cur_y, dir, point; // N: 세로 크기, M: 가로 크기, K: 이동하는 횟수
    static int[][] map;
    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { 1, 0, -1, 0 };
    static boolean[][] visit;
    static int[] dice = { 6, 3, 4, 5, 2, 1 };
    static Queue<int[]> q = new LinkedList<int[]>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        total = 0;
        dir = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        cur_x = 0;
        cur_y = 0;

        for (int i = 0; i < K; i++) {
            // 이동방향으로 갈 수 있는지
            isValid();
            // 이동하기
            move();
            // 점수 획득
            point = 1;
            bfs();
            total += map[cur_x][cur_y] * point;
        }

        System.out.println(total);
    }

    private static void isValid() {
        int nx = cur_x + dx[dir];
        int ny = cur_y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            dir = dir % 2 == 0 ? 2 - dir : 4 - dir;
            nx = cur_x + dx[dir];
            ny = cur_y + dy[dir];
        }
    }

    private static void move() {
        cur_x = cur_x + dx[dir];
        cur_y = cur_y + dy[dir];

        dice_change();
        dir_change();
    }

    public static void dir_change() {
        if (dice[0] > map[cur_x][cur_y]) {
            dir += 1; // 이동 방향 90도 시계 방향으로 회전
        } else if (dice[0] < map[cur_x][cur_y]) {
            dir -= 1;
        }

        if (dir >= 4) {
            dir -= 4;
        }

        else if (dir < 0) {
            dir += 4;
        }
    }

    private static void dice_change() {
        int[] tmp = new int[6];

        for (int i = 0; i < 6; i++) {
            tmp[i] = dice[i];
        }

        if (dir == 0) {
            dice[0] = tmp[1];
            dice[1] = tmp[5];
            dice[2] = tmp[0];
            dice[3] = tmp[3];
            dice[4] = tmp[4];
            dice[5] = tmp[2];
        } else if (dir == 1) {
            dice[0] = tmp[3];
            dice[1] = tmp[1];
            dice[2] = tmp[2];
            dice[3] = tmp[5];
            dice[4] = tmp[0];
            dice[5] = tmp[4];
        } else if (dir == 2) {
            dice[0] = tmp[2];
            dice[1] = tmp[0];
            dice[2] = tmp[5];
            dice[3] = tmp[3];
            dice[4] = tmp[4];
            dice[5] = tmp[1];
        } else if (dir == 3) {
            dice[0] = tmp[4];
            dice[1] = tmp[1];
            dice[2] = tmp[2];
            dice[3] = tmp[0];
            dice[4] = tmp[5];
            dice[5] = tmp[3];
        }
    }

    private static void bfs() {
        visit = new boolean[N][M];
        q.add(new int[] { cur_x, cur_y });
        visit[cur_x][cur_y] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;

                if (map[x][y] == map[nx][ny] && !visit[nx][ny]) {
                    point++;
                    visit[nx][ny] = true;
                    q.add(new int[] { nx, ny });
                }
            }
        }
    }
}

/*
 * 방향을 동남서북으로 맞춰줘서 90도 시계일땐 +1
 * 반시계 90도 일땐 -1 씩으로 dx, dy를 설정한다.
 * 처음 동쪽 방향이니 dir=0 으로 설정
 * isAvailable에서 nx,ny값이 가능한지 보고, 범위 밖이면 dir을 변경
 * move 에서 nx,ny로 이동하고 dice_chage에서 주사위를 굴린다.
 * 주사위는 아래 동 서 남 북 위 으로해서 6 3 4 5 2 1 로 초기 설정
 * 동서남북에 따라서 주사위 값들이 어떻게 변경하는지 하나하나 바꿔주고
 * dir_change에서 주사위 아랫면 숫자와 map[x][y]값에 따라 주사위가 어느 쪽으로 굴려질지 판단
 * 다음 현재위치에서 같은 값에 따라 map[x][y]*갯수 를 total에 더해주고 최종적인 total값을 출력
 */