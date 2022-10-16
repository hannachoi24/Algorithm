package 기본기.문자열;

import java.io.*;

public class 단어뒤집기 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        int T = Integer.parseInt(br.readLine());
        String input = "";

        for (int i = 0; i < T; i++) {
            input = br.readLine();
            String[] split = input.split(" ");
            StringBuilder sb = new StringBuilder();

            for (String s : split) {
                String reverse = new StringBuffer(s).reverse().toString();
                sb.append(reverse).append(' ');
            }

            System.out.println(sb);
        }
    }
}
