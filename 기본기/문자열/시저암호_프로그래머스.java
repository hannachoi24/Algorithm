package 기본기.문자열;

public class 시저암호_프로그래머스 {
    public String solution(String s, int n) {
        String answer = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (Character.isLowerCase(ch)) { // 소문자
                ch = (char) ((ch - 'a' + n) % 26 + 'a'); // (A/a와 원래 문자의 차이 + 밀리는 수 n)을 26으로 나눈 나머지 = 루프를 돌고나서의 차이
                                                         // (결과적으로 밀린 정도)
            }

            else if (Character.isUpperCase(ch)) { // 대문자
                ch = (char) ((ch - 'A' + n) % 26 + 'A');
            }

            answer += ch;
        }
        return answer;
    }
}
