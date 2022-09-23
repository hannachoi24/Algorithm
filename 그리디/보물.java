package 그리디;

import java.util.Arrays;
import java.util.Scanner;

public class 보물 {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] A = new int[n];
        int[] B = new int[n];

        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            B[i] = sc.nextInt();

        }

        Arrays.sort(A);
        Arrays.sort(B);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += A[i] * B[n - 1 - i]; // A와 B의 역방향을 곱해주어야 최소가 나옴
            /*
             * ex) 가장 작은 수가 나올 경우는 A = {1, 2, 3, 4, 5}, B = {1, 3, 5, 7, 9}일 때
             * 1*9 + 2*7 + 3*5 + 4*3 + 5*1
             */
        }

        System.out.println(sum);

    }
}
