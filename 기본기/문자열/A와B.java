package 기본기.문자열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A와B {
    static int res;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder(br.readLine());
        StringBuilder tb = new StringBuilder(br.readLine());

        int flag = 0;
        while (tb.length() > sb.length()) {
            if (tb.charAt(tb.length() - 1) == 'A') {
                tb.delete(tb.length() - 1, tb.length());
            } else {
                tb.delete(tb.length() - 1, tb.length());
                tb.reverse();
            }

            if (tb.length() == sb.length()) {
                if (tb.toString().equals(sb.toString()))
                    flag = 1;
                break;
            }
        }
        System.out.println(flag);
    }
}

/*
 * 매 문자열을 추가하며 S -> T를 탐색하는 방법 대신에 T -> S로 문자열을 줄여가며 탐색하는 방법을 사용해야 한다. 코드로만 봐도
 * 전자의
 * 방법은 문자열 길이 1이 늘어날 때 마다 가지수가 2개씩 늘어나고 후자인 경우 끝자리의 문자만 제거하면 되므로 더 적은 경우의 수로 최적해
 * 탐색을 할 수 있다.
 * (t의 길이 > s의 길이)일 때까지 while반복문을 돌린다. while(tb.length()>sb.length())
 * t의 끝자리가 'A'이면, t의 끝자리 'A'를 삭제한다.
 * t의 끝자리가 'B'이면, t의 끝자리 'B'를 삭제하고 문자열을 뒤집는다.
 * (t의 길이 == s의 길이)이면, while반복문을 종료하고 두 문자열이 일치하면 1, 아니면 0 을 출력한다.
 * if(tb.toString().equals(sb.toString())) flag =1;
 */