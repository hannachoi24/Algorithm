package 완전탐색;

import java.util.Scanner;

public class 영의개수 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        int[] arr = new int[1000001];

        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int cnt = 0;
            for (int j = n; j <= m; j++) {
                arr[j] = j;
                for (int k = 0; k < String.valueOf(arr[j]).length(); k++) {
                    if (String.valueOf(arr[j]).charAt(k) == '0') {
                        cnt++;
                    }
                }
            }
            System.out.println(cnt);
        }
    }
}
