package 시뮬레이션;

import java.io.*;
import java.util.*;

public class 게리맨더링2 {
    static int n;
    static int[][] arr;
    static int totalPeople = 0;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        arr = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                totalPeople += arr[i][j];
            }
        }

        // solution
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int d1 = 1; d1 < n; d1++) {
                    for (int d2 = 1; d2 < n; d2++) {
                        if (x + d1 + d2 >= n)
                            continue;
                        if (y - d1 < 0 || y + d2 >= n)
                            continue;

                        Solution(x, y, d1, d2);

                    }
                }
            }
        }

        System.out.println(min);
    }

    static void Solution(int x, int y, int d1, int d2) {
        boolean[][] border = new boolean[n][n];

        // 경계선 세팅(d1, d2)
        for (int i = 0; i <= d1; i++) {
            border[x + i][y - i] = true;
            border[x + d2 + i][y + d2 - i] = true;
        }

        for (int i = 0; i <= d2; i++) {
            border[x + i][y + i] = true;
            border[x + d1 + i][y - d1 + i] = true;
        }

        int[] peopleSum = new int[5];

        // 1 구역 인구수
        for (int i = 0; i < x + d1; i++) {
            for (int j = 0; j <= y; j++) {
                if (border[i][j])
                    break;
                peopleSum[0] += arr[i][j];
            }
        }

        // 2 구역 인구수
        for (int i = 0; i <= x + d2; i++) {
            for (int j = n - 1; j > y; j--) {
                if (border[i][j])
                    break;
                peopleSum[1] += arr[i][j];
            }
        }

        // 3 구역 인구수
        for (int i = x + d1; i < n; i++) {
            for (int j = 0; j < y - d1 + d2; j++) {
                if (border[i][j])
                    break;
                peopleSum[2] += arr[i][j];
            }
        }

        // 4 구역 인구수
        for (int i = x + d2 + 1; i < n; i++) {
            for (int j = n - 1; j >= y - d1 + d2; j--) {
                if (border[i][j])
                    break;
                peopleSum[3] += arr[i][j];
            }
        }

        // 제 5구역 인구수
        peopleSum[4] = totalPeople;

        for (int i = 0; i < 4; i++) {
            peopleSum[4] -= peopleSum[i];
        }

        // 정렬
        Arrays.sort(peopleSum);

        // 최대 - 최소
        min = Math.min(min, peopleSum[4] - peopleSum[0]);
    }
}

/*
 * <Problem>
 * 
 * 주어진 맵을 5 개의 구역으로 나눈다.
 * 
 * 각 구역의 인구의 합을 구한 뒤 가장 큰 값과 가장 작은 값의 차를 구한다.
 * 
 * 구역을 나눌 수 있는 모든 경우에서 최대값과 최소값의 차를 구한 뒤 이 중에서 가장 작은 수를 구하는 문제이다.
 * 
 * <Solution>
 * 대각선으로 나누어지기도 하고 좌표값이 복잡해보이긴 하지만 문제에서 주어진 대로 구현만 하면 쉽게 풀리는 문제이다.
 * 
 * 1. 4중 for 문으로 (x, y, d1, d2) 경우의 수를 전부 구한다.
 * 2. (x, y) 좌표에서 시작하여 d1, d2 를 기준으로 경계선만 체크한다.
 * 3. 경계선을 기준으로 1, 2, 3, 4 구역의 인구수를 구한다.
 * 4. 5 구역은 (전체 인구수 - 나머지 구역의 인구수) 로 계산한다.
 * 5. 각 구역 인구수를 오름차순으로 정렬한 뒤에 최대값에서 최소값을 빼고 min 배열과 비교해서 최소값을 구한다.
 * 
 * 각 구역의 인구수를 구하는 순서는 아래 그림처럼 위에서부터 아래로, 화살표 순서대로 값을 더한다.
 * 미리 표시해둔 경계선을 만나면 다음 줄로 넘어가는 방식으로 구현하여 5 구역을 전부 알아낼 필요 없이 경계선만 체크.
 */