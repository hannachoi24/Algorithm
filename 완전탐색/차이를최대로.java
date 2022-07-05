package 완전탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 차이를최대로 {
    static int[] nums;
    static boolean[] visited;
    static int[] selected; // 각 순열 케이스를 담아줄 임시 저장소
    static int n;
    static int result = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        nums = new int[n];
        visited = new boolean[n];
        selected = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0);

        System.out.println(result);

    }

    public static void dfs(int count) {
        if (count == n) {
            result = Math.max(getresult(), result);
            return;
        }

        for (int i = 0; i < n; i++) { // 각 순열 케이스 생성
            if (!visited[i]) {
                visited[i] = true;
                selected[count] = nums[i]; // 담는다
                dfs(count + 1); // 재귀로 그 다음 index 늘려간다.
                visited[i] = false; // 다 만들고 false로 해제
            }
        }
    }

    public static int getresult() {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += Math.abs(selected[i] - selected[i + 1]);
        }
        return sum;
    }
}
