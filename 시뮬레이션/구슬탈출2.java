package 시뮬레이션;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 구슬탈출2 {

    static int n, m;
    static int[][] map;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static boolean visit[][][][];
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visit = new boolean[n][m][n][m];

        int rx = 0, ry = 0;
        int bx = 0, by = 0;

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split("");
            for (int j = 0; j < m; j++) {
                // R : 47, B: 31, O : 44, #: 0, . : 11
                int num = line[j].charAt(0) - '0' + 13; // char형을 int형으로 변환
                map[i][j] = num;
                if (num == 47) {
                    rx = i;
                    ry = j;
                } else if (num == 31) {
                    bx = i;
                    by = j;
                }
            }
        }

        bfs(rx, ry, bx, by, 0);
        // 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
        System.out.println(min == Integer.MAX_VALUE ? -1 : min);
    }

    public static void bfs(int rx, int ry, int bx, int by, int cnt) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { rx, ry, bx, by, cnt });
        visit[rx][ry][bx][by] = true;

        while (!q.isEmpty()) {
            int[] pos = q.poll();
            int pCnt = pos[4];

            // 10번 이하로 움직이라는 출력 조건
            if (pCnt >= 10) {
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nRx = pos[0];
                int nRy = pos[1];
                int nBx = pos[2];
                int nBy = pos[3];

                // 빨강 구슬 이동
                while (map[nRx + dx[i]][nRy + dy[i]] != 0) {
                    nRx += dx[i];
                    nRy += dy[i];
                    // 구슬이 벽에 닿거나 구멍에 들어가면 종료
                    if (map[nRx][nRy] == 44) {
                        break;
                    }
                }

                // 파란 구슬 이동
                while (map[nBx + dx[i]][nBy + dy[i]] != 0) {
                    nBx += dx[i];
                    nBy += dy[i];
                    // 구슬이 벽에 닿거나 구멍에 들어가면 종료
                    if (map[nBx][nBy] == 44) {
                        break;
                    }
                }

                // 파란 구슬이 구멍에 들어갔을 때
                if (map[nBx][nBy] == 44) {
                    continue;
                }

                // 빨간 구슬이 구멍에 들어가면 min값 갱신
                if (map[nRx][nRy] == 44) {
                    min = Math.min(min, pCnt + 1);
                    return;
                }

                // 빨강, 파랑 구슬이 서로 만났을 때 해당 이동 거리를 계산해 누가 먼저 도착했는지 알아낸다.
                // (각 구슬의 이동속도는 같으므로 이동거리가 짧은 구슬이 더 빨리 도착했음을 알 수 있다.)
                if (nRx == nBx && nRy == nBy && map[nRx][nRy] != 44) {
                    int red_move = Math.abs(nRx - pos[0]) + Math.abs(nRy - pos[1]);
                    int blue_move = Math.abs(nBx - pos[2]) + Math.abs(nBy - pos[3]);

                    if (red_move > blue_move) {
                        nRx -= dx[i];
                        nRy -= dy[i];
                    } else {
                        nBx -= dx[i];
                        nBy -= dy[i];
                    }
                }

                if (!visit[nRx][nRy][nBx][nBy]) {
                    visit[nRx][nRy][nBx][nBy] = true;
                    q.add(new int[] { nRx, nRy, nBx, nBy, pCnt + 1 });
                }
            }
        }
    }
}

/*
 * 1. 입력받은 String타입 데이터를 Integer타입으로 변환하여 저장해준다. (R : 47, B: 31, O : 44, #: 0,
 * .:11)
 * 2. bfs탐색을 통하여 최소 동작을 통해 빨간 구슬을 구멍으로 빼내는 횟수를 출력한다.
 * 2-1. 빨간 구슬을 이동시킨다. (구슬이 벽에 닿거나 구멍에 들어가면 종료)
 * 2-2. 파란 구슬을 이동시킨다. (구슬이 벽에 닿거나 구멍에 들어가면 종료)
 * 2-3. 이동시킨 파란 구슬이 구멍에 들어가면 해당 방향의 탐색 건너뛰기 continue;
 * 2-4. 이동시킨 빨간 구슬이 구멍에 들어가면 탐색 종료 min = pCnt+1 return;
 * 2-5. 만약 빨간 구슬과 파란 구슬의 위치가 같을 경우 해당 이동 거리를 조사해 누가 먼저 도착했는지 알아낸다.
 * (각 구슬의 이동속도는 같으므로 이동거리가 짧은 구슬이 더 빨리 도착했음을 알 수 있다.)
 * red_move <= blue_move 빨간 구슬이 먼저 도착하거나 같은 경우, 파란 구슬을 이동 방향의 반대 방향으로 한 칸 이동시킨다.
 * (이동거리가 같을 때 빨간 구슬이 우선인 이유는 예제 입력 5를 보고 추측하였다.)
 * blue_move > red_move 파란 구슬이 먼저 도착한 경우, 빨간 구슬을 이동 방향의 반대 방향으로 한 칸 이동시킨다.
 * 3. 방문체크해주고 큐에 위치와 횟수 갱신해서 추가
 */