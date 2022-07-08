package 완전탐색;

import java.util.Scanner;

public class 로마숫자만들기 {
    static int N;
    static int num[] = new int[] { 1, 5, 10, 50 };
    static boolean visited[] = new boolean[1001];
    static int result = 0;

    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        dfs(0, 0, 0);
        System.out.println(result);
    }

    static void dfs(int depth, int idx, int sum) {
        if (depth == N) {
            if (!visited[sum]) {
                visited[sum] = true;
                result++;
            }

            return; // 방문했다면 return
        }

        for (int i = idx; i < 4; i++) {
            // 중복탐색 안되게끔 index 설정
            dfs(depth + 1, i, sum + num[i]);
        }
    }
}
