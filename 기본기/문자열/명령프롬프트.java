package 기본기.문자열;

import java.io.*;

public class 명령프롬프트 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        char[] pattern = br.readLine().toCharArray();

        for (int i = 0; i < N - 1; i++) {
            char[] fileName = br.readLine().toCharArray();
            for (int j = 0; j < pattern.length; j++) {
                if (pattern[j] != fileName[j])
                    pattern[j] = '?';
            }
        }
        System.out.println(pattern);
    }
}

/*
 * 1. 파일 이름의 개수를 입력받고, 비교 기준이 되는 pattern도 입력받는다.
 * 2. N - 1(먼저 입력받은 pattern 제외)만큼 반복문을 돈다.
 * 3. pattern과 입력받은 fileName을 비교해 서로 다른 값이 있다면 '?'로 변경한다.
 * 4. 변경된 pattern을 출력한다.
 */