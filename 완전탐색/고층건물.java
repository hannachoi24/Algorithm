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
