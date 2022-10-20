package 기본기.문자열;

import java.io.*;

public class 유학금지 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] word = "CAMBRIDGE".toCharArray();
        String input = br.readLine();

        for (int i = 0; i < word.length; i++) {
            if (input.indexOf(word[i]) > -1) {
                input = input.replace(String.valueOf(word[i]), "");
            }
        }
        System.out.println(input);
    }
}

/*
 * replace와 replaceAll의 차이점
 * replace : 변환값에 문자열 적용
 * replaceAll : 변환값에 정규식 사용가능
 */