package 기본기.문자열;

import java.io.*;

public class 그룹단어체커 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int cnt = 0;
        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            if (check() == true) {
                cnt++;
            }
        }

        System.out.println(cnt);

    }

    public static boolean check() throws IOException {
        boolean[] check = new boolean[26];
        int prev = 0;
        String str = br.readLine();

        for (int i = 0; i < str.length(); i++) {
            int now = str.charAt(i); // i번째 문자 저장(현재 문자)

            // 앞선 문자와 i 번째 문자가 같지 않다면
            if (prev != now) {
                // 해당 문자가 처음 나오는 경우 (false인 경우)
                if (check[now - 'a'] == false) {
                    check[now - 'a'] = true;
                    prev = now; // 다음 턴을 위해 prev도 바꿔줌
                }

                // 해당 문자가 이미 나온 적이 있는 경우 (그룹단어가 아니게 됨)
                else {
                    return false; // 함수 종료
                }
                // 앞선 문자와 i번째 문자가 같다면 (연속된 문자)
                // else문은 없어도 됨
            } else {
                continue;
            }
        }
        return true;
    }
}
