package 기본기.문자열;

import java.io.*;
import java.util.*;

public class 단어정렬 {
    static int n;
    static String arr[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new String[n];

        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }

        Arrays.sort(arr, new Comparator<String>() {
            public int compare(String s1, String s2) {
                // 단어 길이가 같은 경우
                if (s1.length() == s2.length()) {
                    return s1.compareTo(s2); // compareTo(): 사전순 정렬 -> 리턴 값은 int형으로 나온다.
                } else {
                    return s1.length() - s2.length(); // 단어 길이순으로 정렬
                }
            }
        });

        StringBuilder sb = new StringBuilder();

        sb.append(arr[0]).append('\n');

        for (int i = 1; i < n; i++) {
            // 중복되지 않는 단어만 출력
            if (!arr[i].equals(arr[i - 1])) {
                sb.append(arr[i]).append('\n');
            }
        }

        System.out.println(sb);

    }
}

/*
 * 배열을 특정한 규칙에 의해 정렬하고 싶은 경우 Arrays.sort 메소드에 Comparator을 구현
 * Arrays.sort 에 Comparator 을 써서 compare 메소드를 구현하는 방법으로 접근
 * 
 * compare 메소드 리턴 타입이 왜 int 형이냐고 한다면, 기본적으로 compare 메소드는 3가지 리턴 값에 의해 위치를 바꿀지
 * 결정하게 된다. 3가지 리턴 값이라 하면 다음과 같다.
 * - 양의 정수
 * - 0
 * - 음의 정수
 * 기본적으로 양수일경우 Arrays.sort()에서 정렬 알고리즘에 의해 위치를 바꾸고, 0 이나 음의 정수인 경우는 두 객체의 위치는
 * 바뀌지 않는다.
 * 
 * 예로들어 { 2, 1, 3 } 이라는 배열이 있고, public int compare(int a1, int a2) {return a1
 * -a2}가 있다고 가정해보자.
 * 그렇다면 맨 처음 a1 은 2 가 될테고, a2 는 1이 된다. 즉, 2 - 1 = 1 이므로 양수가 반환되기 때문에 a1 과 a2
 * 즉, 2 와 1 의 위치가 서로 바뀌게 된다. 그러면 { 1, 2, 3 } 이 되겠다.
 * 그 다음 a1, a2 는 각각 2 와 3이 될테고, 2 - 3 = -1 이므로 음수가 반환되어 두 객체 2와 3은 위치가 바뀌지 않는다.
 * 이렇게 compare 메소드는 3가지 반환값에 의해 두 객체(인자)의 우선순위를 판단하고, 이를 정렬알고리즘 안에서 위치를 바꾸거나 그대로
 * 둔다.
 */