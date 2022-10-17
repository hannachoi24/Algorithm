package 기본기.문자열;

import java.io.*;

public class 대소문자바꾸기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String s = br.readLine();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            // 대문자면 소문자로 바꾸기
            if (Character.isUpperCase(c)) {
                sb.append(Character.toLowerCase(c));
            } else {
                // 소문자면 대문자로 바꾸기
                sb.append(Character.toUpperCase(c));
            }
        }
        System.out.print(sb);
    }
}
