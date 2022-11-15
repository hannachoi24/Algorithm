package 기본기.BackTracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 신기한소수 {
    static int N;
    static int[] arr;
    static boolean visit;
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        arr = new int[N];

        dfs("", 0);

        System.out.println(sb.toString());
    }

    public static void dfs(String s, int depth) {
        if (depth == N) {
            sb.append(s + '\n');
            return;
        }

        for (int i = 1; i <= 9; i++) {
            if (isPrime(Integer.parseInt(s + i))) {
                dfs(s + i, depth + 1);
            }
        }
    }

    public static boolean isPrime(int num) {
        if (num == 1)
            return false;

        int sqrt = (int) Math.sqrt(num);

        for (int i = 2; i <= sqrt; i++) {
            if (num % i == 0)
                return false;
        }

        return true;
    }
}
