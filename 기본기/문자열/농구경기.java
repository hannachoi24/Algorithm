package 기본기.문자열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 농구경기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        char[] str = new char[N];
        String result = "";

        for (int i = 0; i < N; i++) {
            str[i] = (br.readLine()).charAt(0); // //입력값의 0인덱스 값만 배열에 저장

        }

        Arrays.sort(str);

        for (int i = 0; i < (N - 1); i++) {
            int cnt = 0;
            for (int j = i + 1; j < N; j++) {
                // 배열의 값이 같고, 비교 값이 0이 아니면 cnt+1
                if (str[i] == str[j] && str[i] != '0') {
                    cnt++;
                    str[j] = '0';
                }
            }
            // 5개 이상인데, 비교하게 되면 같은 횟수가 4이면 5개와 같은 것이다
            if (cnt > 3) {
                result += str[i];
            }
        }

        if (result.equals("")) {
            System.out.println("PREDAJA");
        } else {
            System.out.println(result);
        }
    }
}
