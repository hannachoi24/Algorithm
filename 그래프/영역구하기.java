package 그래프;

import java.io.*;
import java.util.*;

public class 영역구하기 {
    static int M; // 높이
    static int N; // 넓이
    static int K; // 직사각형 개수
    static int[][] map;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static int count = 0; // 영역 구하기
    static ArrayList<Integer> List;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new int[M][N];

        // 직사각형 구해서 영역들 1로 넣기
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken()); // 왼쪽아래
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken()); // 오른쪽 위
            int y2 = Integer.parseInt(st.nextToken());

            for (int a = y1; a < y2; a++) {
                for (int b = x1; b < x2; b++) {
                    map[a][b] = 1;
                }
            }
        }

        List = new ArrayList<Integer>(); // 그 영역 넓이 저장

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 0) {
                    count = 0;
                    DFS(i, j);
                    List.add(count);
                }
            }
        }

        // List에 들어간 넓이의 개수를 구하면 그게 영역의 넓이
        System.out.println(List.size()); // 분리되어 나누어지는 영역의 개수

        Collections.sort(List);

        for (Integer c : List)
            System.out.print(c + " "); // 각 영역의 넓이

    }

    public static void DFS(int x, int y) {
        map[x][y] = 1;
        count++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (map[nx][ny] == 0)
                    DFS(nx, ny);
            }
        }
    }
}