package 기본기.문자열;

import java.util.Scanner;

public class 가장많은글자 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int alpha[] = new int[26];
        int max = 0;
        while (sc.hasNextLine()) {
            String str = sc.nextLine();
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) != ' ') {
                    alpha[str.charAt(i) - 'a']++;
                    if (max < alpha[str.charAt(i) - 'a']) {
                        max = alpha[str.charAt(i) - 'a'];
                    }
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i] == max)
                System.out.print((char) (i + 'a')); // int형을 char형으로 바꿔줌
        }
        sc.close();
    }
}

/*
 * 문자열의 끝을 판단하는 hasNextstr()를 이용하면 무한루프가 발생
 * Nextstr() 메소드는 엔터만을 감지하여 엔터 전까지의 모든것을 입력받겠다는 의미
 * hasNextstr() 메소드는 boolean으로 다음줄에 입력이 있는지 여부를 판단해 입력이 있으면 True, 업다면 false 반환
 * 이를 clase()로 닫아주지 않으면 무한루프에 빠질 수 있다.
 */