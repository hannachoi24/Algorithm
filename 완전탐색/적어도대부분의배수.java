package 완전탐색;

import java.util.Scanner;

public class 적어도대부분의배수 {
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5]; // 입력값들을 저장해줄 배열
        int count = 0; // 몇개의 입력값이 나누어 떨어지는지 체크
        int n = 0; // 결과값 저장 변수

        for (int i = 0; i < 5; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // 몇에서 3개이상이 나눠질지 모르기 때문에 무한루프
        while (true) {
            n++;
            for (int i = 0; i < 5; i++) {
                if (n >= arr[i] && n % arr[i] == 0) // n값을 나눴을때 입력값들이 나누어 떨어지면 count+1
                    count++;
            }
            // 3개이상 나눠지면 무한루프 종료
            if (count > 2)
                break;
            // 3개이상 나눠지지 않았으면 count 초기화
            count = 0;
        }
        System.out.println(n);
    }
}
