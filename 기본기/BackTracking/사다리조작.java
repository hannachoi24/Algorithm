package 기본기.BackTracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
만약 사다리의 수를 2개만 놓았을 때 조건에 만족이 된다면, 사다리 3개 놓았을 때의 모든 경우의 수를 체크하지 않아도 된다. -> 백트래킹
*/

public class Main1 {
    static int n, m, h, answer; // n: 세로선 개수, m: 가로선 개수, h: 각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수
    static int[][] map;
    static boolean finish = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        map = new int[h + 1][n + 1];

        // a 높이에서 b번과 b+1번 세로선을 연결한다.
        int a, b;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            // 1번 높이의 1번과 2번 세로선을 연결하는 가로선이 있다면
            map[a][b] = 1; // 1: 우측으로 이동
            map[a][b + 1] = 2; // 2: 좌측으로 이동
        }

        // 추가할 가로선의 갯수를 미리 정해놔야 탐색 종료 조건으로 걸 수 있다.
        // 아래 반복문에서 i는 추가할 가로선의 수
        for (int i = 0; i <= 3; i++) {
            answer = i;
            dfs(1, 1, 0);
            if (finish)
                break;
        }

        System.out.println((finish) ? answer : -1);
    }

    // cnt: 추가한 가로선의 갯수 (3개가 넘어가면 더이상의 탐색이 무의미)
    public static void dfs(int x, int y, int cnt) {
        if (finish)
            return;
        if (answer == cnt) {
            if (check())
                finish = true;
            return;
        }

        for (int i = y; i <= h; i++) {
            for (int j = x; j < n; j++) {
                // 가로선 두 개가 연속으로 놓여질 수 없기 때문에 가로선을 추가하기 전에 연결된 가로선이 있는지 확인
                if (map[i][j] == 0 && map[i][j + 1] == 0) {
                    // 가로선을 추가
                    map[i][j] = 1;
                    map[i][j + 1] = 2;
                    dfs(1, 1, cnt + 1);
                    map[i][j] = 0; // 추가 했던 가로선 다시 제거(백트래킹)
                    map[i][j + 1] = 0;
                }
            }
        }
    }

    // i번으로 출발해서 i번으로 도착하는지 확인
    public static boolean check() {
        for (int i = 1; i <= n; i++) {
            // 각각의 행에서 출발
            int nx = i;
            int ny = 1;

            while (ny <= h) {
                if (map[ny][nx] == 1)
                    nx++; // 우측으로 이동
                else if (map[ny][nx] == 2)
                    nx--; // 좌측으로 이동
                ny++; // y축+1칸 이동 (=아래로 이동)
            }

            if (nx != i) // i번으로 출발해서 i번으로 도착하지 않는게 하나라도 있다면 리턴
                return false;
        }

        return true;
    }
}
