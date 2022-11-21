package 시뮬레이션;

import java.io.*;
import java.util.*;

public class 마법사상어와토네이도 {
    static int N;
    static int[][] A;
    static int[] dx = { 0, 1, 0, -1 }; // 토네이토의 x 이동 방향
    static int[] dy = { -1, 0, 1, 0 }; // 토네이토의 y 이동 방향
    static int[] dc = { 1, 1, 2, 2 };
    static int[][] dsx = { { -1, 1, -2, -1, 1, 2, -1, 1, 0 }, { -1, -1, 0, 0, 0, 0, 1, 1, 2 }, // 모래가 퍼지는 x방향
            { 1, -1, 2, 1, -1, -2, 1, -1, 0 }, { 1, 1, 0, 0, 0, 0, -1, -1, -2 } };
    static int[][] dsy = { { 1, 1, 0, 0, 0, 0, -1, -1, -2 }, { -1, 1, -2, -1, 1, 2, -1, 1, 0 }, // 모래가 퍼지는 y방향
            { -1, -1, 0, 0, 0, 0, 1, 1, 2 }, { 1, -1, 2, 1, -1, -2, 1, -1, 0 } };
    static int[] sandRatio = { 1, 1, 2, 7, 7, 2, 10, 10, 5 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine().trim());

        A = new int[N][N];

        for (int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int c = 0; c < N; c++) {
                A[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        int result = calculateOutSand(N / 2, N / 2);

        System.out.println(result);
    }

    // 현재위치에서 이동 -> 이동한 위치에서 모래 뿌리기 -> 이동한 위치를 현재위치로 업데이트
    static int calculateOutSand(int x, int y) {
        int totalOutSand = 0;

        int currentX = x;
        int currentY = y;

        while (true) {
            for (int i = 0; i < 4; i++) {
                for (int moveCnt = 0; moveCnt < dc[i]; moveCnt++) {
                    // 현재 위치에서 이동
                    int nx = currentX + dx[i];
                    int ny = currentY + dy[i];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                        return totalOutSand;
                    }

                    // 이동한 위치(비율이 적혀있는 위치)에서 모래 뿌리기
                    int sand = A[nx][ny];
                    A[nx][ny] = 0;
                    int spreadTotal = 0;

                    for (int spread = 0; spread < 9; spread++) {
                        int sandX = nx + dsx[i][spread];
                        int sandY = ny + dsy[i][spread];
                        int spreadAmount = (sand * sandRatio[spread]) / 100;

                        if (sandX < 0 || sandX >= N || sandY < 0 || sandY >= N) {
                            totalOutSand += spreadAmount;
                        } else {
                            A[sandX][sandY] += spreadAmount; // 모래가 이미 있는 칸으로 모래가 이동하면, 모래의 양은 더해짐
                        }
                        spreadTotal += spreadAmount;
                    }

                    // 알파로 이동하는 모래의 양 계산
                    int alphaX = nx + dx[i];
                    int alphaY = ny + dy[i];
                    int alphaAmount = sand - spreadTotal;

                    if (alphaX < 0 || alphaX >= N || alphaY < 0 || alphaY >= N) {
                        totalOutSand += alphaAmount;
                    } else {
                        A[alphaX][alphaY] += alphaAmount; // 모래가 이미 있는 칸으로 모래가 이동하면, 모래의 양은 더해짐
                    }

                    // 이동한 위치를 현재위치로 업데이트
                    currentX = nx;
                    currentY = ny;
                }
            }

            for (int index = 0; index < 4; index++) {
                /*
                 * 이동하는 방향은 ← ↓ → ↑ 순서대로 이동한다. 이때 각 이동방향의 이동 횟수를 보면 1 1 2 2 → 3 3 4 4 → ... 으로
                 * 진행된다.
                 * 이동방향의 한 사이클이 끝나면 이동횟수는 각각 +2로 업데이트 된다.
                 */
                dc[index] += 2;
            }
        }
    }
}
