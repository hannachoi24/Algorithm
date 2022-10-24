package 기본기.문자열;

import java.io.*;
import java.util.*;

public class 이상한곱셈 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String A = st.nextToken();
        String B = st.nextToken();

        long result = 0;

        for (int i = 0; i < A.length(); i++) {
            for (int j = 0; j < B.length(); j++) {
                result += (A.charAt(i) - '0') * (B.charAt(j) - '0');
                // CharAt(int i) - '0'을 통해 char형의 문자들을 int형으로 변환시킬 수 있다.
            }
        }
        System.out.println(result);
    }
}
