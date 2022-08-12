package 그래프;

import java.util.*;
import java.io.*;

public class 숫자판점프 {
    static List<String> list = new ArrayList<>();
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String[][] board = new String[5][5];

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                board[i][j] = st.nextToken();
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dfs(board, i, j, 0, board[i][j]);
            }
        }

        System.out.println(list.size());
    }

    public static void dfs(String[][] board, int x, int y, int cnt, String tmp) {
        if (cnt == 5) { // dfs로 돌리다가 만약 6자리 수가 완성되었다면(cnt == 5) 중복되지 않게 list에 넣어준 후, list의 size를 출력
            if (!list.contains(tmp)) {
                list.add(tmp);
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                dfs(board, nx, ny, cnt + 1, tmp + board[nx][ny]);
            }
        }
    }
}
