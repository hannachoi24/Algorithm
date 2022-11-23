package 시뮬레이션;

import java.io.*;
import java.util.*;

class 연구소3 {

    static class Virus {
        int x, y, time;

        Virus(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }

    static int N, M;
    static int[][] map;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static List<Virus> viruses = new ArrayList<>(); // 바이러스 위치 저장할 배열
    static Virus[] active; // 활성 바이러스
    static int minTime = Integer.MAX_VALUE;
    static int originEmptySpace = 0; // 본래 0은 빈 칸, 바이러스 퍼진 후 0은 활성 바이러스

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        active = new Virus[M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());

                if (map[i][j] == 0) {
                    originEmptySpace++;
                } else if (map[i][j] == 2) {
                    viruses.add(new Virus(i, j, 0));
                }
            }
        }

        // Solution
        if (originEmptySpace == 0) {
            System.out.println(0);
        } else {
            selectVirus(0, 0);
            System.out.println(minTime == Integer.MAX_VALUE ? -1 : minTime);
        }
    }

    // 백트래킹으로 M개의 바이러스를 선택하는 Combination 구현
    static void selectVirus(int start, int cnt) {
        if (cnt == M) {
            spreadVirus(originEmptySpace);
            return;
        }

        for (int i = start; i < viruses.size(); i++) {
            active[cnt] = viruses.get(i);
            selectVirus(i + 1, cnt + 1);
        }
    }

    // bfs로 바이러스 퍼뜨리기
    static void spreadVirus(int emptySpace) {
        Queue<Virus> q = new LinkedList<>();
        boolean[][] infected = new boolean[N][N];

        for (int i = 0; i < M; i++) {
            Virus virus = active[i];
            infected[virus.x][virus.y] = true;
            q.add(virus);
        }

        while (!q.isEmpty()) {
            Virus virus = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = virus.x + dx[i];
                int ny = virus.y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if (infected[nx][ny] || map[nx][ny] == 1)
                    continue;

                if (map[nx][ny] == 0) {
                    emptySpace--;
                }

                if (emptySpace == 0) { // 빈 공간이 없으면 결과 출력
                    minTime = Math.min(minTime, virus.time + 1);
                    return;
                }

                infected[nx][ny] = true;
                q.add(new Virus(nx, ny, virus.time + 1)); // 이동한 위치 현재위치로 업데이트 및 시간 1초씩 증가
            }
        }
    }
}

/*
 * 비활성화된 바이러스들 때문에 바이러스가 전부 퍼졌는지 확인하는 건 빈 공간의 갯수로 파악하는 것이 훨씬 효과적이다.
 */