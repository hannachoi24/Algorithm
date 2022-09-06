package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 로프 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int[] rope = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            rope[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(rope);

        int max = 0;

        for (int i = 0; i < rope.length; i++) {
            int weight = rope[i] * (rope.length - i);
            max = max > weight ? max : weight;
        }

        System.out.println(max);
    }
}

/*
 * 최대 중량을 구하는 것이라서 배열을 한번 순환했다.
 * 해당 로프가 버틸 수 있는 최소 중량 * 로프 수
 */