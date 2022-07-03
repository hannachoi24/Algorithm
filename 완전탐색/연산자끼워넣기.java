package 완전탐색;

import java.util.Scanner;

public class 연산자끼워넣기 {
    public static int MAX = Integer.MIN_VALUE; // 최댓값
    public static int MIN = Integer.MAX_VALUE; // 최솟값
    public static int[] operator = new int[4]; // 연산자 개수
    public static int[] number; // 숫자
    public static int N; // 숫자 개수

    @SuppressWarnings("resource")
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        N = in.nextInt();
        number = new int[N];

        // 숫자 입력
        for (int i = 0; i < N; i++) {
            number[i] = in.nextInt();
        }

        // 연산자 입력
        for (int i = 0; i < 4; i++) {
            operator[i] = in.nextInt();
        }

        dfs(number[0], 1);

        System.out.println(MAX);
        System.out.println(MIN);
    }

    public static void dfs(int num, int idx) {
        if (idx == N) {
            MAX = Math.max(MAX, num);
            MIN = Math.min(MIN, num);
            return;
        }

        for (int i = 0; i < 4; i++) {
            // 연산자 개수가 1개 이상인 경우
            if (operator[i] > 0) {

                // 해당 연산자를 1 감소시킨다.
                operator[i]--;

                switch (i) {
                    case 0:
                        dfs(num + number[idx], idx + 1);
                        break;
                    case 1:
                        dfs(num - number[idx], idx + 1);
                        break;
                    case 2:
                        dfs(num * number[idx], idx + 1);
                        break;
                    case 3:
                        dfs(num / number[idx], idx + 1);
                        break;
                }
                // 재귀호출이 종료되면 다시 해당 연산자 개수를 복구한다.
                operator[i]++;
            }
        }
    }
}

/*
 * 여기서 셋 째 줄을 입력 받고, 각 연산자를 배열로 두어 수를 두면 되지 않을까?
 * 즉, 4칸의 배열에 각각 연산자의 개수를 입력하고, 반복문안에서 재귀호출을 해주는 것이다.
 * 그리고 재귀호출 때 마다 해당 연산자 인덱스를 1 감소시키며 0이 된다면 다음 인덱스(연산자)로 넘어간다.
 * 재귀호출과정에서 만약 모든 연산자를 썼을 경우(idx == N) 해당 값이 최대인지, 최소인지를 판별
 */