package 완전탐색;

import java.util.Scanner;

public class 숫자야구 {
    private static int n, cnt = 0;
    private static boolean num[] = new boolean[988];

    public static void chek(int number, int strike, int ball) {
        int a = number / 100, b = number % 100 / 10, c = number % 100 % 10;

        for (int i = 123; i < 988; i++) {
            if (num[i])
                continue;
            int a2 = i / 100, b2 = i % 100 / 10, c2 = i % 100 % 10, strike2 = 0, ball2 = 0;
            if (a2 == 0 || b2 == 0 || c2 == 0 || a2 == b2 || b2 == c2 || a2 == c2) {
                num[i] = true;
                continue;
            }
            if (a == a2)
                strike2++;
            if (b == b2)
                strike2++;
            if (c == c2)
                strike2++;
            if (a == b2 || a == c2)
                ball2++;
            if (b == a2 || b == c2)
                ball2++;
            if (c == b2 || c == a2)
                ball2++;
            if (strike != strike2 || ball != ball2)
                num[i] = true;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++)
            chek(sc.nextInt(), sc.nextInt(), sc.nextInt());
        for (int i = 123; i < 988; i++)
            if (!num[i] == true)
                cnt++;
        System.out.println(cnt);

    }
}

/*
 * 123부터 987까지의 i를 N과 비교하면서
 * 
 * 스트라이크와 볼의 개수를 세어준 뒤
 * 
 * 입력된 스트라이크와 볼의 개수와 비교해주고
 * 
 * 같으면 배열[i]에 1을, 다르면 -1을 저장한다.
 * 
 * 
 * N과 i를 비교할 때 주의할 점은
 * 
 * 세 자리가 각각 다른 숫자로 구성되어 있어야 하고, 0이 포함되면 안 된다.
 * 
 * 이 부분만 주의해주면 된다.
 */