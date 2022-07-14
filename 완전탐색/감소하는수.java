package 완전탐색;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class 감소하는수 {
    static ArrayList<Long> list;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        list = new ArrayList<>();

        if (n <= 10)
            System.out.println(n);
        else if (n > 1022)
            System.out.println("-1");
        else {
            for (int i = 0; i < 10; i++) {
                Solution(i, 1);
            }
            Collections.sort(list);
            System.out.println(list.get(n));
        }
    }

    public static void Solution(long num, int idx) {
        if (idx > 10)
            return;

        list.add(num);
        for (int i = 0; i < num % 10; i++) {
            Solution((num * 10) + i, idx + 1);
        }
    }
}

/*
 * 제일 첫 번째 뽑는 수를 기준으로 감소하는 수를 만들어서 list에 저장하고, list를 정렬하여 n번째 수를 반환하도록 하였다.
 * 예를들어서 아래와 같당.
 * 
 * 처음에 뽑는 수/ 다음에 올 수 있는 수/ 만들어 지는 수
 * 1/ 0/ 10
 * 2/ 1, 0/ 21, 20, 210
 * 3/ 2, 1, 0/ 32, 31, 30, 321, 320
 * 
 * 
 * 현재까지 뽑은 수가 num이라고 했을때, num을 10으로 나눈 나머지보다 작은 값만 다음에 올 수 있다.
 * 
 * 그리고 수를 뽑으면 num * 10을 한 다음 그 수에 i를 더한 값이 된다. 식으로 표현하면 아래와 같다.
 * 
 * for(int i = 0; i < num % 10; i++) {
 * Solution((num * 10) + i, idx + 1);
 * }
 * 
 * 
 * 이 문제의 조건에 따라 n이 10보다 작거나 같다면 그 수를 그대로 반환해 주어 빠르게 출력해 주고, 1022보다 크면(만들 수 있는 최대
 * 감소하는 수인 9876543210이 1022번째이다.) -1을 출력하여 계산을 하지 않고 빠르게 출력될 수 있도록 했다.
 */
