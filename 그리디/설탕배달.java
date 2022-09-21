package 그리디;

import java.util.*;

/*
5로 나눠지면 바로 출력
5로 안 나눠지면 3씩 빼서 0이 된다면 다시 첫 번째 if문으로 돌아가 bong 출력
3씩 빼서 음수가 나오면 -1 출력
*/

public class 설탕배달 {
    static int[] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int bong = 0;

        while (true) {
            if (N % 5 == 0) {
                bong += N / 5;
                System.out.println(bong);
                break;
            } else {
                N -= 3;
                bong++;
            }

            if (N < 0) {
                System.out.println("-1");
                break;
            }
        }
    }
}
