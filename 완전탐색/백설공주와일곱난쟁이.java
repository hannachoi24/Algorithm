package 완전탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 백설공주와일곱난쟁이 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] arr;
    static int[] select = new int[7];
    // 9C7 조합

    public static void main(String[] args) throws IOException {
        arr = new int[9];
        for (int i = 0; i < 9; i++) {
            arr[i] = stoi(br.readLine());
        }
        combination(0, 0);
    }

    private static void combination(int cnt, int start) {
        if (cnt == 7) {
            int total = 0;
            for (int i = 0; i < select.length; i++)
                total += select[i];
            if (total == 100) {
                for (int i = 0; i < select.length; i++)
                    System.out.println(select[i]);
            }
            return;
        }

        // 재귀를 사용해서 combination이 뽑힐 때마다 cnt 와 start를 1씩 증가시켜 중복을 피함
        for (int i = start; i < arr.length; i++) {
            select[cnt] = arr[i];
            combination(cnt + 1, i + 1); // i + 1: 뽑힌 인덱스 기준으로 다음 인덱스부터 뽑아야하기 때문
        }
    }

    public static int stoi(String input) {
        return Integer.parseInt(input);
    }
}