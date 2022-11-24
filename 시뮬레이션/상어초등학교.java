package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class 상어초등학교 {
    static int N;
    static int[][] map;
    static int dx[] = { -1, 1, 0, 0 };
    static int dy[] = { 0, 0, -1, 1 };
    static int result = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        map = new int[N + 1][N + 1];
        // 각 학생마다 선호하는 학생 값을 넣어준다.
        HashMap<Integer, ArrayList<Integer>> check = new HashMap<Integer, ArrayList<Integer>>();

        for (int i = 0; i < N * N; i++) {
            st = new StringTokenizer(br.readLine());
            int student = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            ArrayList<Integer> likeStudents = new ArrayList<>();
            likeStudents.add(a);
            likeStudents.add(b);
            likeStudents.add(c);
            likeStudents.add(d);

            check.put(student, likeStudents);

            int near = -1;
            int empty = -1;
            int x = 0;
            int y = 0;

            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    int tempNear = 0;
                    int tempEmpty = 0;
                    // 이미 학생이 있으면 넘어간다.
                    if (map[j][k] != 0) {
                        continue;
                    }

                    for (int z = 0; z < 4; z++) {
                        int nx = j + dx[z];
                        int ny = k + dy[z];
                        if (nx <= 0 || nx > N || ny <= 0 || ny > N) {
                            continue;
                        }

                        // 해당 자리의 있는 학생이 선호하는 학생인지 확인
                        if (map[nx][ny] > 0 && (map[nx][ny] == a) || (map[nx][ny] == b) || (map[nx][ny] == c)
                                || (map[nx][ny] == d)) {
                            tempNear++;
                            // 빈칸인지 확인
                        } else if (map[nx][ny] == 0) {
                            tempEmpty++;
                        }
                    }

                    // 선호하는 학생이 가장 많을 경우
                    if (tempNear > near) {
                        near = tempNear;
                        empty = tempEmpty;
                        x = j;
                        y = k;
                        // 선호하는 학생이 동알한데 빈공간이 많을 경우
                    } else if (tempNear == near && tempEmpty > empty) {
                        near = tempNear;
                        empty = tempEmpty;
                        x = j;
                        y = k;
                    }
                }
            }
            map[x][y] = student; // 순서대로 해당 자리에 학생 앉힘
        }

        // 자리배치가 완전히 끝난 후 점수 메김
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx <= 0 || nx > N || ny <= 0 || ny > N) {
                        continue;
                    }
                    if (check.get(map[i][j]).contains(map[nx][ny])) {
                        cnt++;
                    }
                }

                // 근처에 있는 학생 수 만큼 점수를 더해줌
                if (cnt == 1) {
                    result += 1;
                } else if (cnt == 2) {
                    result += 10;
                } else if (cnt == 3) {
                    result += 100;
                } else {
                    result += 1000;
                }
            }
        }

        System.out.println(result);
    }
}
