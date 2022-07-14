package 완전탐색;

import java.util.Scanner;

public class 문자열 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();

        int result = a.length();

        for (int i = 0; i < b.length() - a.length() + 1; i++) {
            int cnt = 0;
            for (int j = 0; j < a.length(); j++) {
                if (a.charAt(j) != b.charAt(j + i)) { // a문자열 길이가 b문자열 길이보다 작거나 같기 때문에
                    cnt++;
                }

            }
            if (result > cnt) { // 최소 차이
                result = cnt;
            }
        }
        System.out.println(result);
    }
}

/*
 * A 문자열과 같은 길이의 B의 부분 문자열을 반복적으로 비교하며 최소 차이를 찾으면 된다.
 * 예를들어 A = "aabb" , B = "bbaabc"라고 가정한다면 B 문자열에서 맨 앞부터 A의 길이의 맞는 문자열로 비교
 * aabb와 (1) "bbaa"bc (2) b"baab"c (3) bb"aabc" 이런식으로 최소차이를 보이는 부분을 찾으려면 결국 모든
 * 문자열을 순회하며 찾아줘야 한다.
 */