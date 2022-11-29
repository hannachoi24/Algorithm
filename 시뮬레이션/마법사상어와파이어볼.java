package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 마법사상어와파이어볼 {
    static int N, M, K;
    static int r, c, m, s, d;
    static List<FireBall> list; // 파이어볼 정보 저장 list
    static Queue<FireBall>[][] map;
    static int[] dx = { -1, -1, 0, 1, 1, 1, 0, -1 };
    static int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        list = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken()) - 1;
            c = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            list.add(new FireBall(r, c, m, d, s));

        }

        map = new Queue[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = new LinkedList<>();
            }
        }

        while (K-- > 0) {
            move();
            combAndDiv();
        }

        int answer = 0;
        for (FireBall f : list) {
            answer += f.m; // 파이어볼 질량의 합 구하기
        }

        System.out.println(answer);
    }

    // 1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
    public static void move() {
        for (FireBall f : list) {
            // 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
            f.r = (N + f.r + dx[f.d] * (f.s % N)) % N;
            f.c = (N + f.c + dy[f.d] * (f.s % N)) % N;

            // 이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있다.
            map[f.r][f.c].add(f);
        }
    }

    // 2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
    public static void combAndDiv() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j].size() >= 2) {
                    int m_sum = 0, s_sum = 0;
                    int cnt_sum = map[i][j].size(); // 합쳐진 파이어볼의 개수
                    boolean odd = true, even = true;

                    // 2-1. 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
                    while (!map[i][j].isEmpty()) {
                        FireBall f = map[i][j].poll();

                        m_sum += f.m; // 합쳐진 파이어볼 질량 합
                        s_sum += f.s; // 합쳐진 파이어볼 속력 합

                        // 파이어볼 방향이 모두 홀수이거나 모두 짝수인지
                        if (f.d % 2 == 0) {
                            odd = false;
                        } else {
                            even = false;
                        }
                        list.remove(f);
                    }

                    // 3. 나누어진 파이어볼의 질량, 속력, 방향 계산
                    int nm = m_sum / 5; // 질량 = (합쳐진 파이어볼 질량의 합)/5
                    int ns = s_sum / cnt_sum; // 속력 = (합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)

                    // 질량이 0인 파이어볼은 소멸되어 없어진다.
                    if (nm == 0)
                        continue;

                    // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
                    if (odd | even) {
                        for (int k = 0; k < 8; k += 2) { // 방향 0,2,4,6
                            list.add(new FireBall(i, j, nm, k, ns));
                        }
                    } else {
                        for (int k = 1; k < 8; k += 2) { // 방향 1,3,5,7
                            list.add(new FireBall(i, j, nm, k, ns));
                        }
                    }
                } else {
                    map[i][j].clear();

                }
            }
        }
    }

    public static class FireBall {
        int r, c, m, d, s;

        public FireBall(int r, int c, int m, int d, int s) {
            this.r = r;
            this.c = c;
            this.m = m;
            this.d = d;
            this.s = s;
        }
    }
}
