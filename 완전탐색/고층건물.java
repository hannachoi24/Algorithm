package 완전탐색;

import java.io.*;
import java.util.*;

public class 고층건물 {
    static int n;
    static int[] height;
    static int[] visible;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        height = new int[n];
        visible = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            height[i] = Integer.parseInt(st.nextToken());
        }
        count();

        Arrays.sort(visible);
        System.out.println(visible[visible.length - 1]);
    }

    private static void count() {
        for (int i = 0; i < n - 1; i++) {
            visible[i] += 1; // 바로 옆 건물은 무조건 보인다.
            visible[i + 1] += 1;
            double slope = height[i + 1] - height[i];

            for (int j = i + 2; j < n; j++) {
                double nextSlope = (double) (height[j] - height[i]) / (j - i);
                if (nextSlope <= slope)
                    continue;
                slope = nextSlope;
                visible[i]++;
                visible[j]++;
            }
        }
    }
}

/*
 * 건물 A에서 건물 B가 보인다면, 건물 B에서도 건물 A가 보인다.
 * -> 인덱스가 증가하는 방향으로만 검사하면 된다.
 * 1. 건물 A에서 건물 B를 볼 수 있으려면 저장된 slope보다 A-B의 기울기가 커야 한다.
 * 2-1. 건물 B가 보이지 않으면 다음 건물을 검사한다.
 * 2-2. 건물 B가 보인다면, visible[A]와 visible[B]를 1씩 증가시키기고 slope를 A-B의 기울기로 갱신한 뒤 다음
 * 건물을 검사한다.
 */