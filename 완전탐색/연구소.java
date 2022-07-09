package 완전탐색;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class 연구소 {

    // 바이러스 객체
    static class virus {
        int x, y;

        virus(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int n; // 지도의 세로 크기
    static int m; // 지도의 가로 크기

    static int[][] map; // 초기 맵 배열
    static int[][] temp; // 벽을 설치한 뒤의 맵 배열

    static int[] dr = { -1, 1, 0, 0 }; // 상하좌우
    static int[] dc = { 0, 0, -1, 1 };

    static int result = Integer.MIN_VALUE; // 안전지역 개수

    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt(); // 지도의 세로 크기
        m = sc.nextInt(); // 지도의 가로 크기

        map = new int[n][m];
        temp = new int[n][m];

        // 지도 입력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        temp = map; // 지도 카피
        // 벽 세우면서 바이러스 뿌리기 시작
        dfs(0);
        System.out.println(result);
    }

    // 벽 세우기
    public static void dfs(int depth) {
        // 벽 3개를 다 세웠으면 바이러스 뿌리기
        if (depth == 3) {
            BFS();
            return;
        }

        // 벽 3개를 못 세웠으면 다시 세우기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    dfs(depth + 1);
                    // 다시 돌려놓기
                    map[i][j] = 0;
                }
            }
        }
    }

    public static void BFS() {
        int[][] virus_map = new int[n][m];
        Queue<virus> que = new LinkedList<virus>();

        // virus map 카피
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                virus_map[i][j] = map[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 바이러스라면 큐에 넣기
                if (virus_map[i][j] == 2)
                    que.add(new virus(i, j));
            }
        }

        while (!que.isEmpty()) {
            virus v = que.remove();

            // 바이러스가 사방으로 퍼질 수 있는 경우
            for (int i = 0; i < 4; i++) {
                int nr = v.x + dr[i];
                int nc = v.y + dc[i];

                // 범위 안에 있으면
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    // 빈칸(0)이라면 바이러스 퍼뜨리고 다시 큐에 넣음
                    if (virus_map[nr][nc] == 0) {
                        virus_map[nr][nc] = 2;
                        que.add(new virus(nr, nc));
                    }
                }
            }
        }
        safe(virus_map);
    }

    public static void safe(int[][] virus_map) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (virus_map[i][j] == 0) {
                    count += 1;
                }

            }

        }
        result = Math.max(count, result);

    }

}