package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 테트로미노 {
    static int N, M;
    static int[][] board;
    static int dx[] = { -1, 1, 0, 0 };
    static int dy[] = { 0, 0, -1, 1 };
    static boolean[][] visit;
    static int max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        visit = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 전체 탐색(dfs)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visit[i][j] = true;
                solve(i, j, board[i][j], 1);
                visit[i][j] = false;
            }
        }

        System.out.println(max);
    }

    static void solve(int x, int y, int sum, int cnt) {
        // 테트로미노 완성 시 수들의 합 계산
        if (cnt == 4) {
            max = Math.max(max, sum);
            return;
        }

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (!visit[nx][ny]) {
                // 보라색(ㅗ) 테트로미노 만들기 위해 2번째 칸에서 탐색 한번 더 진행
                if (cnt == 2) {
                    visit[nx][ny] = true;
                    solve(x, y, sum + board[nx][ny], cnt + 1);
                    visit[nx][ny] = false;
                }

                visit[nx][ny] = true;
                solve(nx, ny, sum + board[nx][ny], cnt + 1);
                visit[nx][ny] = false;
            }
        }
    }
}

/*
 * 탐색의 2번째 칸에서
 * 양쪽으로 하나씩 움직여야 만들 수 있는 형태이기 때문에 상하좌우 탐색으로는 결과를 구할 수 없다.
 * 따라서 탐색 시 2번째 칸 일때, 3번째 탐색을 시작하는 위치를 3번째 탐색 위치로 하는 것이 아니라
 * 2번째 칸에서 다시 한번 탐색하도록 하는 경우를 추가해주면 구할 수 있다.
 */