package 기본기.문자열;

import java.util.Arrays;

public class 파일명정렬_프로그래머스 {
    public String[] solution(String[] files) {
        Arrays.sort(files, (o1, o2) -> {
            String head1 = o1.split("[0-9]")[0].toLowerCase(); // split("[0-9]") -> 문자열에서 숫자 한 글자를 기준으로 문자열을 자르는 경우에 사용
            String head2 = o2.split("[0-9]")[0].toLowerCase();
            if (head1.compareTo(head2) == 0) { // head가 같은 문자열일 경우 number로 정렬
                String numTail1 = o1.substring(head1.length()); // head가 끝나는 부분 부터 이후의 값 가져옴
                String numTail2 = o2.substring(head2.length());
                return Integer.parseInt(calNumber(numTail1)) - Integer.parseInt(calNumber(numTail2));
            } else {
                return head1.compareTo(head2);
            }
        });
        return files;
    }

    private static String calNumber(String numTail2) {
        StringBuilder sb = new StringBuilder();
        for (char c : numTail2.toCharArray()) {
            if (Character.isDigit(c) && sb.length() <= 5) { // 최대 5자리인 number 계산
                sb.append(c);
            } else {
                return sb.toString();
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        파일명정렬_프로그래머스 solution = new 파일명정렬_프로그래머스();
        solution.solution(
                new String[] { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01000000.GIF", "img2.JPG" });
    }
}

/*
 * <split>
 * 문자를 자를 때 사용
 * split("[0-9]") -> 문자열에서 숫자 한 글자를 기준으로 문자열을 자르는 경우에 사용
 * split("[a-z]") -> 문자열에서 영소문자 한 글자 기준으로 문자열을 자르는 경우에 사용
 * 
 * <substring>
 * ex) substring(5)이면 index 값이 5인 위치 부터 이후 값을 가져오는 것
 * 공백문자도 하나의 문자이므로 한자리를 차지
 * 
 * substring(int beginIndex, int endIndex)
 * beginIndex 위치에서 시작하여 endIndex 전 위치까지의 값을 리턴
 * ex) substring(6, 12) ==> index 6 위치에서 index 12 - 1 위치(11 자리) 까지의 값을 리턴
 * 
 * Character.isDigit(c)
 * 명시된 char 값이 숫자 인지 여부를 판단해 true 또는 false 값으로 리턴.
 */