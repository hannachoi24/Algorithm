package 완전탐색;

import java.util.Scanner;

public class 토너먼트 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int zimin = sc.nextInt();
        int hansu = sc.nextInt();
        int count = 0; // 라운드

        while (zimin != hansu) {
            zimin = zimin / 2 + zimin % 2;
            hansu = hansu / 2 + hansu % 2;
            count++;
        }
        System.out.println(count);

    }

}
