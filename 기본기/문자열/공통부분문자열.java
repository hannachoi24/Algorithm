package 기본기.문자열;

import java.io.*;

public class 공통부분문자열 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();

        int len1 = str1.length();
        int len2 = str2.length();
        int max = 0;
        int[][] map = new int[len1 + 1][len2 + 1];

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    map[i][j] = map[i - 1][j - 1] + 1;
                    max = Math.max(max, map[i][j]);
                }
            }
        }
        System.out.println(max);
    }
}

/*
 * 공통 문자열의 갯수는 가로, 세로에 동일한 문자가 오는 경우 대각선으로 늘어난다.
 * 표를 채워가면서 행과 열이 같은 문자일 경우 좌측 상단 + 1만큼 늘어나면서 max값을 갱신해준다.
 * 대각선을 처리하기가 곤란할 수도 있다.
 * 따라서, 두 문자열의 길이가 각각 n, m일 때 int[n][m] 을 만들지 말고 int[n+1][m+1]을 만들어서 해결하도록 한다.
 */