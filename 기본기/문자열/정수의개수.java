package 기본기.문자열;

import java.io.*;
import java.util.StringTokenizer;

public class 정수의개수 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int cnt = 0;

        String input = st.nextToken();

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);

            if (c == ',') {
                cnt++;
            }
        }
        System.out.println(cnt + 1);

    }
}
