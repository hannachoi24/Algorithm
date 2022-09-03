package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 거스름돈 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] coins = { 500, 100, 50, 10, 5, 1 };

        int K = 1000;
        int pay = Integer.parseInt(br.readLine());
        int change = K - pay;
        int result = 0;

        for (int i = 0; i < coins.length; i++) {
            if (coins[i] > change) {
                continue;
            }
            result += (change / coins[i]);
            change = change % coins[i];
        }

        System.out.println(result);
    }
}
