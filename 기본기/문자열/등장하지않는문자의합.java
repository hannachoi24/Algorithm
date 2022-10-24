package 기본기.문자열;

import java.io.*;

public class 등장하지않는문자의합 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String str = br.readLine();

            boolean[] alpha = new boolean[26];
            for (int j = 0; j < str.length(); j++) {
                if (!alpha[str.charAt(j) - 'A'])
                    alpha[str.charAt(j) - 'A'] = true; // 'A' - 'A' = 0, 'B' - 'A' = 1 ...
            }

            int ans = 0;
            int cnt = 0;
            for (int j = 0; j < alpha.length; j++) {
                if (!alpha[j]) { // false 이면
                    ans += j;
                    cnt++;
                }
            }
            ans += cnt * 65;
            bw.write(ans + "\n");

        }
        bw.flush();
        br.close();
        bw.close();
    }
}

/*
 * 총 대문자의 개수 26개 만큼의 boolean 배열을 만들어 주고, 수학적으로 문자열 S에 등장하지 않는 알파벳 대문자의 아스키 코드 값을
 * ans에 더해주는 방식으로 문제를 푼다.
 */