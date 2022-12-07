package 시뮬레이션;

import java.io.*;
import java.util.*;

public class 상어중학교 {
    static int N, M, answer; // N: 크기, M: 색상 개수
    static int map[][];
    static int dx[] = { 1, 0, -1, 0 }; // 우 하 좌 상
    static int dy[] = { 0, 1, 0, -1 };
    static LinkedList<Block> list = new LinkedList<>(); // point list
    static Queue<int[]> q = new LinkedList<int[]>(); // 블록 위치 정보 저장 배열
    static boolean[][] visit;

    static private class Block implements Comparable<Block> {
        int totalPoint, rainbowPoint, row, col;

        public Block(int totalPoint, int rainbowPoint, int row, int col) {
            this.totalPoint = totalPoint;
            this.rainbowPoint = rainbowPoint;
            this.row = row;
            this.col = col;
        }

        // 기준 블록은 행, 열이 작은 것으로 잡아줘야한다.
        public int compareTo(Block o) {
            if (this.totalPoint == o.totalPoint) {
                if (this.rainbowPoint == o.rainbowPoint) {
                    if (this.row == o.row) {
                        return o.col - this.col;
                    }
                    return o.row - this.row;
                }
                return o.rainbowPoint - this.rainbowPoint;
            }
            return o.totalPoint - this.totalPoint;
        }

    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        visit = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (true) {
            // 1. 크기가 가장 큰 블록 그룹을 찾는다. 2 이상 아니면 break -> bfs로 찾음
            visit = new boolean[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (map[i][j] > 0 && visit[i][j] == false) {
                        bfs(i, j, true);
                    }
                }
            }
            if (list.isEmpty())
                break;

            Collections.sort(list);
            // 찾은 블록 없애기
            visit = new boolean[N][N];
            bfs(list.get(0).row, list.get(0).col, false);
            removeBlock();

            // 중력
            gravity();
            // 반시계방향 회전
            map = rotate();
            // 중력
            gravity();

            list.clear();
        }
        System.out.println(answer);
    }

    // 2. 1에서 찾은 블록 그룹의 모든 블록을 제거한다. (블록 그룹에 포함된 블록의 수를 B라고 했을 때, B2점을 획득한다.)
    private static void removeBlock() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j] == true) {
                    cnt++;
                    map[i][j] -= 2;
                }
            }
        }
        answer += (int) Math.pow(cnt, 2);
    }

    // 3 & 5. 격자에 중력이 작용
    // 격자에 중력이 작용하면 검은색 블록을 제외한 모든 블록이 행의 번호가 큰 칸으로 이동한다.
    // 이동은 다른 블록이나 격자의 경계를 만나기전까지 계속 된다.
    private static void gravity() {
        for (int j = 0; j < N; j++) {
            for (int i = N - 1; i >= 0; i--) {
                for (int k = i; k < N - 1; k++) {
                    if (map[k][j] == -1)
                        continue; // 검은색 블록을 제외
                    if (map[k][j] != -2 && map[k + 1][j] == -2) {
                        int temp = map[k][j];
                        map[k][j] = -2;
                        map[k + 1][j] = temp;
                    }
                }
            }
        }
    }

    // 4. 반시계 방향 회전
    public static int[][] rotate() {
        int[][] temp = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[N - j - 1][i] = map[i][j];
            }
        }
        return temp;
    }

    // 크기가 가장 큰 블록 그룹 찾기
    private static void bfs(int x, int y, boolean flag) {
        int blockPoint = map[x][y];
        visit[x][y] = true;
        q.offer(new int[] { x, y });
        int totalPoint = 1;
        int rainbowPoint = 0;

        while (!q.isEmpty()) {
            int cur[] = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny > N || visit[nx][ny] == true)
                    continue;
                if (map[nx][ny] == blockPoint || map[nx][ny] == 0) {
                    if (map[nx][ny] == 0)
                        rainbowPoint += 1;
                    totalPoint += 1;
                    visit[nx][ny] = true;
                    q.offer(new int[] { nx, ny });
                }
            }
        }

        if (totalPoint >= 2)
            list.add(new Block(totalPoint, rainbowPoint, x, y));

        if (flag == true) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (map[i][j] == 0)
                        visit[i][j] = false;
                }
            }
        }
    }
}

/*
 * 1번 -> bfs로 찾았음. comparable을 활용하여 블록 개수, 무지개 블록 갯수, 행, 열 순으로 정렬시켜준다.
 * 2번 -> 같은 bfs를 구현하여 visit에 true로 표시하고 true인 값들을 모두 -2로 바꾸어준다.
 * 3번 -> gravity() 함수를 구현하였고 -1은 움직이지 않는다.
 * 4번 -> 반시계 방향 회전(그냥 외우는것도 방법)
 * 5번 -> 다시 gravity 활용
 */