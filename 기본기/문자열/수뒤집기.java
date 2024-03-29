package 기본기.문자열;

import java.io.*;

public class 수뒤집기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        for (int j = 0; j < N; j++) {
            String str = br.readLine();
            int number = Integer.parseInt(new StringBuilder(str).reverse().toString()) + Integer.parseInt(str);
            str = String.valueOf(number);
            boolean No = false;
            for (int i = 0; i < str.length() / 2; i++) {
                if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                    No = true;
                    break;
                }
            }
            if (No)
                bw.write("NO");
            else
                bw.write("YES");
            bw.write("\n");
        }
        bw.flush();

    }
}
