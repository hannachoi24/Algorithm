package 시뮬레이션;

import java.util.*;
import java.io.*;

public class 달팽이2 {
    static int N, M;
    static int[][] map;

    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { 1, 0, -1, 0 };

    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        M = sc.nextInt();
        N = sc.nextInt();
        sc.close();

        map = new int[M][N];
        visited = new boolean[M][N];

        int cnt = 0; // 출력할 꺽은 횟수
        int sum = 0; // 지나온 칸 수 -> 종료 조건으로 사용

        int idx = 0; // 다음 칸 탐색할 때 쓸 인덱스
        int nowX = 0;
        int nowY = 0;

        visited[nowX][nowY] = true;
        sum = 1;

        while (idx < 4) {
            int nx = nowX + dx[idx];
            int ny = nowY + dy[idx];

            // 모든 칸을 지나왔다면 답 출력하고 종료
            if (sum == N * M) {
                System.out.println(cnt);
                return;
            }

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny]) {
                sum++;
                visited[nx][ny] = true;
                nowX = nx;
                nowY = ny;
            }

            else {
                idx++; // 다음 탐색할 방향으로 전환
                cnt++;
            }

            // 마지막 방향 인덱스까지 왔으면 다시 맨 처음 탐색 방향으로 전환
            if (idx >= 4) {
                idx = 0;
            }
        }
    }
}