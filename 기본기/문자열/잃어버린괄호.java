package 기본기.문자열;

import java.io.*;

/*-가 왔을때 기준으로 그 뒤로는 다 - 연산을 해주는 것이다.
*/

public class 잃어버린괄호 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();
        String num = ""; // 숫자를 저장할 변수
        int result = 0; // 결과값을 저장 할 변수
        boolean minus = false; // -가 등장한 기점을 파악하기 위한 변수

        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) != '-' && S.charAt(i) != '+') {
                num += S.charAt(i);
            }
            // 연산 기준은 -또는 +가 등장 했을때, 또는 마지막 값까지 입력 되었을 때이다.
            if (S.charAt(i) == '-' || S.charAt(i) == '+' || i == S.length() - 1) {

                // minus가 false면 더하기, true면 빼기를 해준다.
                if (!minus) {
                    result += Integer.parseInt(num);
                } else {
                    result -= Integer.parseInt(num); // 최종 -> 5 -= 40
                }
                // num을 연산해줬으면 초기화
                num = "";
            }

            // -가 등장하면 minus에 true를 저장.
            if (S.charAt(i) == '-') {
                minus = true;
            }
        }
        System.out.println(result);
    }
}
