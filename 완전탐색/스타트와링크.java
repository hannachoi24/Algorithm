package 완전탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 스타트와링크 {
    static int n;
    static int min = Integer.MAX_VALUE;
    public static int[][] arr;
    public static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        visit = new boolean[n];

        // 능력치 배열 입력
        for (int i = 0; i < n; i++) {
            StringTokenizer str = new StringTokenizer(br.readLine());
            for (int j = 0; str.hasMoreTokens(); j++) {
                arr[i][j] = Integer.parseInt(str.nextToken());
            }
        }

        dfs(0, 0);

        System.out.println(min);
    }

    // 팀 나누기
    public static void dfs(int depth, int a) {
        if (depth == n / 2) { // depth == n / 2일 때 즉 4명이 된다면, 해당 DFS를 멈추고 diff함수를 호출해 시너지의 합 구함
            diff();
            return;
        }

        /*
         * 항상 DFS를 구현할 때는 IF문과 FOR문을 사용해야 합니다. 그중에 FOR문을 통해 팀을 나누어 준다.
         * 여기서 visit 변수는 각 팀을 결정 true가 들어간 인덱스는 start팀, false가 들어간 인덱스는 link팀으로 판별
         * for문에 i = a가 들어간 이유는 dfs를 통해 계속 재귀하면서 그 이전 값들을 변경하면 안 되기 때문
         * 물론 마지막에 visit [i] = false;를 넣어준 것은 당연히 dfs를 통해 4명을 뽑아내기 위함
         */
        for (int i = a; i < n; i++) {
            visit[i] = true;
            dfs(depth + 1, i + 1);
            visit[i] = false;
        }
    }

    // 나눈 팀(방문 여부로 구분) 시너지합 계산하기
    public static void diff() {
        int start = 0;
        int link = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (visit[i] == true && visit[j] == true) {
                    start += arr[i][j];
                    start += arr[j][i];
                } else if (visit[i] == false && visit[j] == false) {
                    link += arr[i][j];
                    link += arr[j][i];
                }
            }
        }

        // 스사트 팀 링크 팀 능력치의 최소 차이 구하기
        int val = Math.abs(start - link);

        // 제일 작은 최소 차이는 0 -> 바로 출력하고 프로그램 종료
        if (val == 0) {
            System.out.println(val);
            System.exit(0);
        }
        // 제일 작은 값 출력
        min = Math.min(min, val);

    }
}