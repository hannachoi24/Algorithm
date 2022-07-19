package 완전탐색;

import java.util.*;

public class 카드놓기 {
    static int n = 0, k = 0; // n: 카드개수, k: 뽑을 개수
    static int arr[], list[]; // arr: 카드 n장의 숫자를 넣을 배열, list: 뽑은 숫자를 넣을 배열
    static boolean visit[];
    static HashSet<Integer> set = new HashSet<>(); // 중복 방지를 위해 HashSet 사용

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();
        arr = new int[n];
        list = new int[k];
        visit = new boolean[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        dfs(0);

        System.out.println(set.size());
    }

    private static void dfs(int depth) {
        if (depth == k) { // 전부 다 뽑았으면
            String sum = "";
            for (int i = 0; i < list.length; i += 1) {
                sum += list[i];
            }
            set.add(Integer.parseInt(sum));
            return;
        }

        for (int i = 0; i < n; i++) { // 재귀함수를 이용해 아직 뽑지 않았으면 한장을 뽑고 그 다음 번호부터 하나씩 뽑는다.
            if (!visit[i]) {
                visit[i] = true;
                list[depth] = arr[i];
                dfs(depth + 1);
                visit[i] = false;
            }
        }
    }
}

/*
 * n개의 카드 중 k개를 뽑았을 때 모든 경우의 수를 전부 계산
 * 단, 중복값이 발생하기 때문에 HashSet에 넣어주면 중복된 값은 입력되지 않는다.
 * HashSet을 사용하는 이유는 중복을 방지하기 위해
 */