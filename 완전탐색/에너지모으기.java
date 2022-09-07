package 완전탐색;

import java.util.*;
import java.io.*;

public class 에너지모으기 {
    static List<Integer> marbles = new ArrayList<Integer>();
    static int power = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            marbles.add(Integer.parseInt(st.nextToken()));
        }

        dfs(n, marbles, 0);

        System.out.println(power);
    }

    private static void dfs(int n, List<Integer> marbles, int sum) {
        if (n == 2) { // 첫번째와 마지막 구슬만 남으면 모두 고른 것이기 때문에 최대값 갱신
            power = Math.max(sum, power);
            return;
        }

        for (int i = 1; i < marbles.size() - 1; i++) { // 첫번째와 마지막 구슬은 제외
            int s = marbles.get(i - 1) * marbles.get(i + 1); // 양쪽 구슬을 곱한 값
            int temp = marbles.get(i); // 구슬 x를 선택해 temp에 넣음
            marbles.remove(i); // 선택한 구슬 x를 배열에서 제거
            dfs(n - 1, marbles, sum + s); // 재귀 호출 dfs(구슬 개수 - 1, 구슬x 제외한 배열, s를 더한 sum값)
            marbles.add(i, temp); // 인덱스 i에 구슬x를 제자리에 삽입
        }
    }
}
