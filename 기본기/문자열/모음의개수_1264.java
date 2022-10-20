package 기본기.문자열;

import java.io.*;

public class 모음의개수_1264 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String str = br.readLine();

            if (str.equals("#"))
                break;

            int cnt = 0;

            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I'
                        || c == 'O'
                        || c == 'U') {
                    cnt++;
                }
            }
            System.out.println(cnt);

        }
    }
}
