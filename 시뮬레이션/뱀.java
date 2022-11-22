package 시뮬레이션;

import java.util.*;
import java.io.*;

public class 뱀 {
    static int N, K, d = 0; // N: 보드의 크기, K: 사과의 개수, d: 방향
    static int L; // 뱀의 방향 변환 횟수
    static int[][] map;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static Map<Integer, String> moveInfo; // 움직임에 대한 정보

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());

        map = new int[N][N];
        moveInfo = new HashMap<>();

        // 사과 위치 입력 받기
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            map[a][b] = 1;
        }

        L = Integer.parseInt(br.readLine());
        // 뱀의 방향 변환 정보 입력 받기
        for (int i = 0; i < L; i++) {
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            String direction = st.nextToken();
            moveInfo.put(time, direction);
        }

        solve();
    }

    static void solve() {
        Queue<Integer> q = new LinkedList<>();
        q.add(0); // 뱀의 시작 위치 저장
        int time = 0;
        int px = 0;
        int py = 0;

        while (true) {
            int nx = px + dx[d];
            int ny = py + dy[d];
            time++; // 이동하면 시간 증가

            // 벽 부딪히면 종료
            if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
                break;
            }

            // 몸통 부딪히면 종료
            if (q.contains(ny * N + nx)) {
                break;
            }

            // 이동한 칸에 사과 있으면
            if (map[ny][nx] == 1) {
                map[ny][nx] = 0; // 칸에 있던 사과 없어짐
                q.add(ny * N + nx); // 머리가 새롭게 움직인 곳 큐에 넣어줌
            } else {
                q.add(ny * N + nx); // 머리가 새롭게 움직인 곳 큐에 넣어줌
                q.poll(); // 꼬리가 위치한 칸을 비워줌
            }

            // 방향전환
            if (moveInfo.containsKey(time)) { // 카운트해준 시간이 Map의 Key에 존재하면 방향 바꾸기
                String data = moveInfo.get(time);
                if (data.equals("D")) {
                    d += 1;
                    if (d == 4)
                        d = 0;
                } else {
                    d -= 1;
                    if (d == -1)
                        d = 3;
                }
            }

            // 현위치 새로 이동한 위치로 업데이트
            px = nx;
            py = ny;
        }

        System.out.println(time);
    }
}

/*
 * while 반복문을 사용하여 한 싸이클(시뮬레이션)을 돌려주면 된다. 뱀의 위치 정보는 queue를 사용한다.
 * queue 사용 이유 : 새로운 칸으로 이동할 때마다 먼저 들어온 꼬리 칸 부분을 빼놔야 하기 때문이다.
 * 
 * 1. 설정된 방향으로 뱀의 머리를 움직인다.
 * 이 때, 움직인 곳이 벽이거나 몸통이면 while문을 종료시킨다.
 * 2. 움직임이 가능하면 그곳이 사과가 있는지 체크한다.
 * 사과가 있으면 queue 데이터는 그대로 냅두고 사과를 먹어준다. 그리고 머리가 새롭게 움직인 곳을 queue에 넣어준다.
 * 사과가 없으면 꼬리 부분의 데이터는 삭제(q.poll())하고 머리가 새롭게 움직인 곳을 queue에 넣어준다.
 * 3. 해당 시간이 방향 변환 정보가 있는지 확인해주고 있으면 방향을 바꿔준다.
 */