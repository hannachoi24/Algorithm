package TwoPointer;

import java.io.*;
import java.util.*;

public class 부분합 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());

        int[] arr = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0, end = 0, sum = 0, len = Integer.MAX_VALUE;

        while (start <= end && end <= N) {
            if (sum < S) {
                sum += arr[end++];
            } else if (sum >= S) {
                len = Math.min(len, end - start);
                sum -= arr[start++];
            }
        }
        System.out.println(len == Integer.MAX_VALUE ? 0 : len);

    }
}

/*
 * 1. 배열을 입력받는다.
 * 2. start, end 투 포인터를 설정하여 탐색한다.
 * 2-1. 연속된 부분합 중 s 이상인 구간의 길이를 구한다.
 * 2-2. sum < s, 값이 작으므로 end포인터 위치에 있는 배열값을 더해준다.
 * 2-3. sum >= s, 값이 크거나 같으므로 start 포인터 위치에 있은 배열값을 빼준다.
 * 3. 구한 부분합의 길이 중 가장 짧은 길이를 출력한다.
 */