package 완전탐색;

import java.io.*;
import java.util.*;

public class 연구소2 {
    static class info {
        int x, y;

        public info(int x, int y) {
            super();
            this.x = x;
            this.y = y;
        }
    }

    static int N, M, time = Integer.MAX_VALUE;
    static int[][] map, copy;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static ArrayList<info> list = new ArrayList<>(); // 바이러스가 놓일 수 있는 위치 list에 담기
    static ArrayList<info> select = new ArrayList<>();
    static Queue<info> q = new LinkedList<>();
    static boolean[][] selected;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); // 연구소 크기
        M = Integer.parseInt(st.nextToken()); // 바이러스 개수

        map = new int[N][N];
        selected = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 1)
                    map[i][j] = -1; // 벽은 -
                else if (map[i][j] == 2) {
                    list.add(new info(i, j));
                    map[i][j] = 0; // 바이러스를 놓은 위치는 0
                }
            }
        }
        comb(0, 0);
        if (time == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(time);
    }

    // 조합을 이용해 전체 바이러스 개수 중 M개 선택하기
    public static void comb(int cnt, int start) {
        if (cnt == M) {
            // 바이러스 퍼지기 & 최소 시간 확인
            spread();
            return;
        }

        for (int i = start; i < list.size(); i++) {
            int x = list.get(i).x;
            int y = list.get(i).y;
            if (selected[x][y])
                continue;

            select.add(new info(x, y));
            selected[x][y] = true;

            comb(cnt + 1, i + 1);
            selected[x][y] = false;
            select.remove(select.size() - 1);
        }
    }

    // 선택한 바이러스 퍼뜨리기
    public static void spread() {
        transfer();
        copy();

        while (!q.isEmpty()) {
            info temp = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = temp.x + dx[i];
                int ny = temp.y + dy[i];

                if (nx < N && nx >= 0 && ny < N && ny >= 0 && !selected[nx][ny] && copy[nx][ny] == 0) {
                    copy[nx][ny] = copy[temp.x][temp.y] + 1;
                    q.add(new info(nx, ny));
                }
            }
        }

        if (time() != -1 && time > time())
            time = time();
    }

    public static void copy() {
        copy = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                copy[i][j] = map[i][j];
            }
        }
    }

    public static void transfer() {
        for (int i = 0; i < select.size(); i++) {
            q.add(new info(select.get(i).x, select.get(i).y));
        }
    }

    // 바이러스가 퍼지는 최소 시간 구하기
    public static int time() {
        int min = 0, count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (copy[i][j] > min)
                    min = copy[i][j];
                if (copy[i][j] == 0)
                    count++;
            }
        }
        if (count != M)
            return -1;
        return min;
    }
}

/*
 * 모든 빈칸에 바이러스를 퍼뜨리는 최소 시간을 구하는 문제
 * 
 * 1. 바이러스가 놓일 수 있는 연구소 위치를 list에 담기
 * 2. 조합을 이용해 전체 바이러스 개수 중 M개 선택하기
 * 3. 선택한 바이러스 퍼뜨리기
 * 4. 바이러스가 퍼지는 최소 시간 구하기
 * 이 순서로 구현
 * 
 * 조합을 이용해 M개의 바이러스 놓을 칸을 정했다면 spread() 메서드에서 상 하 좌 우로 이동하면서
 * 바이러스를 퍼지게한다. 모든 바이러스가 퍼진 뒤에는, 최소 시간을 구해야 하기 때문에 time() 메서드를 통해서
 * 모든 빈 칸에 바이러스가 퍼졌는지 확인과 함께 퍼뜨리는 최소 시간을 구해주었다.
 * 이렇게 모든 바이러스가 놓일 수 있는 경우를 확인한 후 가장 최소 시간을 마지막에 출력해준다.
 */
