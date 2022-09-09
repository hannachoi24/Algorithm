package 완전탐색;

import java.io.*;

public class 반지 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String target; // 찾고자 하는 문자열
        int n; // 반지 수
        int cnt = 0; // 찾고자하는 문자를 포함하는 반지의 수

        target = br.readLine();
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            s += s;

            if (s.contains(target))
                cnt++;
        }

        System.out.println(cnt);

    }
}
