package 완전탐색;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

@SuppressWarnings("resource")
public class 부등호 {
    static boolean[] check = new boolean[10]; // 0~9까지 체크
    static int n;
    static char[] arr = new char[10]; // 부등호는 최대 9개
    static ArrayList ans = new ArrayList<>();

    static boolean ck(char a, char b, char c) {
        // 현재 사용하는 숫자와 i번째 숫자와 비교하여, 부등호가 성립되면 true
        if (c == '<') {
            if (a > b) {
                return false;
            }
        }
        if (c == '>') {
            if (a < b) {
                return false;
            }
        }

        return true;
    }

    static void go(int index, String num) {
        if (index == n + 1) {
            ans.add(num); // 부등호가 성립되는 모든 경우의 수가 등록
            return;
        }

        for (int i = 0; i <= 9; i++) {
            // 사용한 숫자인지 체크
            if (check[i])
                continue;
            if (index == 0 || ck(num.charAt(index - 1), (char) (i + '0'), arr[index - 1])) {
                check[i] = true;
                go(index + 1, num + Integer.toString(i));
                check[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            arr[i] = sc.next().toCharArray()[0];
        }

        go(0, "");
        Collections.sort(ans);

        System.out.println(ans.get(ans.size() - 1));
        System.out.println(ans.get(0));
    }
}

/*
 * 1. 전역변수로 선언해야 할 것들을 생각한다.
 * 
 * -> 0~9의 숫자가 사용되었는지 확인할 배열
 * 
 * -> 부등호가 저장될 배열
 * 
 * -> 입력받을 변수 n
 * 
 * -> 결과 값이 저장될 ArrayList
 * 
 * 2. 중복된 숫자가 들어가면 안되기때문에 check배열을 이용하여 이미 사용한 숫자면 continue, 그렇지 않다면 다음 index로
 * 넘어간다.
 * 
 * 3. 인덱스를 탐색하면서 부등호 조건에 맞는지 또한 함께 탐색한다.
 * 
 * 4. ArrayList 정렬을 통해 맨 마지막과 처음을 출력함으로써 최대값, 최소값을 구할 수 있다.
 * 
 */