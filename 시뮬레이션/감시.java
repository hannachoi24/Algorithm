package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class 감시 {
    static int n, m;
    static int[][] map; // 이전 단계에서의 맵
    static int[][] map_copy; // 현재 단계에서의 맵
    static int[] output; // 순열을 담을 배열
    static ArrayList<CCTV> cctvList;
    static int[] dx = { -1, 0, 1, 0 }; // 상 우 하 좌(시계방향 순서)
    static int[] dy = { 0, 1, 0, -1 };
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer((br.readLine()));

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        cctvList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] != 0 && map[i][j] != 6) {
                    cctvList.add(new CCTV(map[i][j], i, j)); // cctv면 좌표 저장
                }
            }
        }

        output = new int[cctvList.size()]; // 순열을 담을 배열
        permutation(0, cctvList.size());

        System.out.println(min);
    }

    // DFS로 상하좌우 4방향 중에서 cctv의 총 개수 r만큼을 순서대로 뽑는 순열을 구함
    public static void permutation(int depth, int r) {
        if (depth == r) { // r만큼의 순열을 모두 뽑았다는 것
            // Copy original 'map' array
            map_copy = new int[n][m];
            for (int i = 0; i < map.length; i++) {
                System.arraycopy(map[i], 0, map_copy[i], 0, map[i].length);
            }

            /*
             * map -> 이전 단계까지의 맵
             * map_copy -> 현재 단계에서의 맵.
             * 카메라 방향의 경우의 수에 따라 다른 맵이 되므로 하나의 경우의 수 처리가 끝나면 반드시 초기화(이전단계의 맵) 해준다.
             */

            // cctv번호와 순열로 뽑혀진 방향에 맞는 상하좌우 방향 설정
            for (int i = 0; i < cctvList.size(); i++) {
                direction(cctvList.get(i), output[i]);
            }

            // 사각지대 구하기
            getBlindSpot();
            return;
        }

        for (int i = 0; i < 4; i++) {
            output[depth] = i;
            permutation(depth + 1, r);
        }
    }

    // 각 cctv 번호와 순열로 뽑혀진 방향에 맞게 감시
    public static void direction(CCTV cctv, int d) {
        int cctvType = cctv.type;

        if (cctvType == 1) {
            if (d == 0)
                watch(cctv, 0); // 상
            else if (d == 1)
                watch(cctv, 1); // 우
            else if (d == 2)
                watch(cctv, 2); // 하
            else if (d == 3)
                watch(cctv, 3); // 좌
        } else if (cctvType == 2) {
            if (d == 0 || d == 2) {
                watch(cctv, 0);
                watch(cctv, 2); // 상하
            } else {
                watch(cctv, 1);
                watch(cctv, 3); // 좌우
            }
        } else if (cctvType == 3) {
            if (d == 0) {
                watch(cctv, 0); // 상우
                watch(cctv, 1);
            } else if (d == 1) {
                watch(cctv, 1); // 우하
                watch(cctv, 2);
            } else if (d == 2) {
                watch(cctv, 2); // 하좌
                watch(cctv, 3);
            } else if (d == 3) {
                watch(cctv, 0); // 좌상
                watch(cctv, 3);
            }
        } else if (cctvType == 4) {
            if (d == 0) {
                watch(cctv, 0); // 좌상우
                watch(cctv, 1);
                watch(cctv, 3);
            } else if (d == 1) {
                watch(cctv, 0); // 상우하
                watch(cctv, 1);
                watch(cctv, 2);
            } else if (d == 2) {
                watch(cctv, 1); // 좌하우
                watch(cctv, 2);
                watch(cctv, 3);
            } else if (d == 3) {
                watch(cctv, 0); // 상좌하
                watch(cctv, 2);
                watch(cctv, 3);

            }
        } else if (cctvType == 5) { // 상우하좌
            watch(cctv, 0);
            watch(cctv, 1);
            watch(cctv, 2);
            watch(cctv, 3);
        }
    }

    // BFS로 방향에 맞게 감시
    public static void watch(CCTV cctv, int d) {
        Queue<CCTV> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];

        q.add(cctv);
        visited[cctv.x][cctv.y] = true;

        while (!q.isEmpty()) {
            int nx = q.peek().x + dx[d];
            int ny = q.peek().y + dy[d];

            // 범위를 벗어나거나 벽을 만나면 끝
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map_copy[nx][ny] == 6) {
                break;
            }

            if (map_copy[nx][ny] == 0) {
                map_copy[nx][ny] = -1; // 빈칸이라면 감시할 수 있다는 의미로 -1
                q.add(new CCTV(cctv.type, nx, ny)); // 해당 cctv 좌표 저장
            } else { // 다른 cctv가 있거나 이미 감시된 칸이라면
                q.add(new CCTV(cctv.type, nx, ny)); // 그냥 통과시키고 큐에 새로운 좌표만 넣어준다
            }
        }
    }

    // 사각지대 구하기
    public static void getBlindSpot() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map_copy[i][j] == 0) { // 현재 단계 map에서 0은 사각지대를 의미
                    cnt++;
                }
            }
        }
    }

}

class CCTV {
    int type;
    int x;
    int y;

    public CCTV(int type, int x, int y) {
        this.type = type;
        this.x = x;
        this.y = y;
    }
}

/*
 * 1~5번까지 cctv를 90도씩 돌려가며 조합해서 사각지대의 최솟값을 구해야 한다.
 * 
 * 방향을 바꾸는 과정은 시계방향으로 상 우 좌 하로 0, 1, 2, 3 순서이다.
 * 1번의 경우 4가지, 2번 2가지, 3번 4가지, 4번 4가지, 5번 1가지의 경우가 나온다.
 * 
 * 예를 들어 1번과 2번 CCTV를 가진 사무실이 있다면
 * 1번 카메라로 나올 수 있는 방향 가짓수는 4,
 * 2번 카메라로 나올 수 있는 방향 가지수는 2로 총 8가지의 경우의 수가 나오고
 * 이 8가지를 바탕으로 감시를 하고, 가장 최소 사각지대를 가진 경우가 정답이 되는 것이다.
 * 
 * 즉, 1~5까지의 CCTV가 가지는 방향에 대한 순열을 구한다고 생각하면 모든 경우를 구할 수 있다.
 * 순열은 n개의 값 중에서 r개의 숫자를 순서대로 뽑는 경우를 말한다.
 * 이를 적용해 4개의 방향 중에서 CCTV의 총 개수 r만큼을 순서대로 뽑아 나올 수 있는 모든 방향의 경우를 따져보는 것!
 * DFS를 이용해 순열을 구해준다.
 * 
 * 예를 들어 1~3까지의 CCTV가 있다면
 * (0, 0, 0), (0, 0, 1) (0, 0, 2)... (0, 1, 1)... (1, 1, 1) ... (3, 3, 3)
 * 1~5까지의 CCTV가 있다면
 * (0, 0, 0, 0, 0)... (0, 1, 2, 2, 3)... (3, 3, 3, 3, 3)
 */