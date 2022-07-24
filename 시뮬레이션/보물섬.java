package 시뮬레이션;

import java.io.*;
import java.util.*;

public class 보물섬 {
    static int N, M, answer;
    static char[][] map;
    static Queue<int[]> queue = new LinkedList<int[]>();
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new char[N][M];

        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = tmp.charAt(j);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 'L') {
                    bfs(i, j);
                }
            }
        }
        System.out.println(answer);
    }

    private static void bfs(int x, int y) {
        int[][] visited = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = -1;
            }
        }

        visited[x][y] = 0;
        queue.offer(new int[] { x, y });

        while (!queue.isEmpty()) {
            int[] cur = queue.poll(); // 큐에서 뺀 현위치를 cur 배열에 저장
            int curX = cur[0];
            int curY = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;

                if (map[nx][ny] == 'L' && visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[curX][curY] + 1;
                    queue.offer(new int[] { nx, ny });
                    answer = Math.max(answer, visited[nx][ny]);
                }
            }
        }
    }
}

/*
 * bfs로 해결 가능한 문제
 * 
 * 'L' 육지인 상황마다 가장 먼 육지와의 거리를 계산해주는 문제
 * 
 * visited 를 -1로 모두 초기화해서 현재 위치와 가장 먼 육지를 계산하고
 * 
 * bfs가 진행될 때마다 현재 가장 먼 거리를 가지고 있는 answer와 비교
 */