package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class 감시_CleanCode {
    static int n, m;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 }; // 상하좌우
    static int[][][] move = { // move[cctv번호][방향의 경우의 수][세부 방향]
            { { 0 } },
            { { 0 }, { 1 }, { 2 }, { 3 } },
            { { 0, 1 }, { 2, 3 } },
            { { 0, 2 }, { 0, 3 }, { 1, 2 }, { 1, 3 } },
            { { 0, 1, 2 }, { 0, 1, 3 }, { 1, 2, 3 }, { 0, 2, 3 } },
            { { 0, 1, 2, 3 } }
    };
    static ArrayList<XY> cctv = new ArrayList<>();
    static int cctv_n;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int map[][] = new int[n][m];
        int empty_area = n * m;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (1 <= map[i][j] && map[i][j] <= 5) {
                    cctv.add(new XY(map[i][j], i, j)); // 시시티비면 좌표 저장
                } else if (map[i][j] == 6) { // 벽이면
                    empty_area--; // 빈공간 갯수 하나 줄이기
                }
            }
        }
        cctv_n = cctv.size(); // 시시티비의 갯수 저장
        select_direction(0, empty_area - cctv_n, map);
        System.out.println(min);

    }

    // 카메라 방향을 정하는 함수
    public static void select_direction(int cnt, int empty, int[][] map) {

        if (cnt == cctv_n) {

            min = Math.min(min, empty); // 사각지대 갯수 비교

            return;
        }

        int[][] map_copy = new int[n][m];
        // map -> 이전 단계까지의 맵
        // map_copy -> 현재 단계에서의 맵.
        // 카메라 방향의 경우의 수에 따라 다른 맵이 되므로 하나의 경우의 수 처리가 끝나면 반드시 초기화(이전단계의 맵) 해준다.

        for (int i = 0; i < n; i++) { // 맵 복사
            for (int j = 0; j < m; j++) {
                map_copy[i][j] = map[i][j];
            }
        }

        // cnt번째 cctv 타입에 따른 모든 방향의 경우의 수를 따져줌
        for (int i = 0; i < move[cctv.get(cnt).type].length; i++) {

            int count = 0;
            for (int j = 0; j < move[cctv.get(cnt).type][i].length; j++) { // 방향 하나하나씩 해보기.
                count += make_area(cctv.get(cnt).x, cctv.get(cnt).y, move[cctv.get(cnt).type][i][j], map_copy);
            }
            select_direction(cnt + 1, empty - count, map_copy); // 다음단계로 진행
            for (int k = 0; k < n; k++) { // 다음 cctv 방향도 고려해봐야하므로 초기화
                for (int j = 0; j < m; j++) {
                    map_copy[k][j] = map[k][j];
                }
            }
        }
    }

    // 사각지대를 없애는 함수
    public static int make_area(int x, int y, int d, int[][] map) {

        int cnt = 0;
        while (true) {
            x += dx[d];
            y += dy[d];
            if (0 > x || 0 > y || n <= x || m <= y || map[x][y] == 6) { // 범위에서 벗어나거나 벽을 만나면 cnt 리턴
                return cnt;
            }
            if (map[x][y] == 0) { // 빈칸인경우
                cnt++;
                map[x][y] = -1;
            }
        }
    }
}

class XY {
    int type;
    int x;
    int y;

    public XY(int type, int x, int y) {
        super();
        this.type = type;
        this.x = x;
        this.y = y;
    }

}
