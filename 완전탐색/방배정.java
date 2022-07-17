package 완전탐색;

import java.util.Scanner;

public class 방배정 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int n = sc.nextInt();
        int ans = 0;

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                for (int k = 0; k < 50; k++) {
                    if ((a * i) + (b * j) + (c * k) == n)
                        ans = 1;
                }
            }
        }
        System.out.println(ans);
    }
}
