package 그래프;

import java.io.*;
import java.util.*;

/*
DFS + DP
DFS 만으로 풀기에 시간이 너무 오래걸리므로 DP 알고리즘도 함께 적용한다.
*/

public class 문자판 {
    static int N, M, K;
    static int cnt = 0;
    static char[][] board;
    static int dx[] = { 0, 1, 0, -1 };
    static int dy[] = { -1, 0, 1, 0 };
    static String target; // 찾는 글자
    static boolean[][] visit;
    static int dp[][][]; // 메모라이징 필요

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        board = new char[N][M];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = str.charAt(j);
            }
        }

        target = br.readLine();
        dp = new int[N][M][target.length()];

        // 모두 -1 담아준다.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < target.length(); k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        // dfs로 갈때마다 count 1 (새로운 단어를 만들어주는 경로로 가는것임.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cnt += dfs(i, j, 0);
            }
        }
        System.out.println(cnt);
    }

    // DFS 구현
    public static int dfs(int i, int j, int index) {
        // DP에 알맞는 값을 채워 넣는다.
        // 1 방문했는데 가능성 있다. 2 방문했는데 가능성 없다 -1 방문하지 않았다.
        if (index == target.length() - 1) // index 마지막에 왔다는 체크, count 하게 1로 리턴
            return dp[i][j][index] = 1;
        if (dp[i][j][index] != -1) // -1이 아니면, 1아니면 2 이다 끝난 결과 값이므로 return
            return dp[i][j][index];
        if (board[i][j] != target.charAt(index)) // 찾는글자가 아니다. 0으로
            return dp[i][j][index] = 0;

        dp[i][j][index] = 0;

        // 4자리 글자 체크
        for (int d = 0; d < 4; d++) {
            for (int k = 1; k <= K; k++) {
                int nx = j + dx[d] * k;
                int ny = i + dy[d] * k;

                // 맵의 범위를 벗어나거나 다음 문자가 정답 문자열과 같을 경우 다음 DFS 진행
                if (0 <= ny && ny < N && 0 <= nx && nx < M && board[ny][nx] == target.charAt(index + 1)) {
                    dp[i][j][index] += dfs(ny, nx, index + 1);
                }

            }
        }
        return dp[i][j][index];
    }
}
