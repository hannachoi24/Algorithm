package 그래프;

import java.io.*;
import java.util.*;

public class 촌수계산 {
    static List<Integer>[] relation;
    static boolean[] checked;
    static int res = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        relation = new ArrayList[n + 1];
        checked = new boolean[n + 1];

        for (int i = 1; i < n + 1; i++) {
            relation[i] = new ArrayList<>();
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken()); // 촌수를 계산해야 하는 서로 다른 두 사람의 번호1
        int y = Integer.parseInt(st.nextToken()); // 촌수를 계산해야 하는 서로 다른 두 사람의 번호2
        int m = Integer.parseInt(br.readLine()); // 부모 자식들 간의 관계의 개수

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            // 부모 자식간의 관계를 나타내는 두 번호 a, b
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            relation[a].add(b);
            relation[b].add(a);
        }

        dfs(x, y, 0);
        System.out.println(res);

    }

    static void dfs(int start, int end, int cnt) {
        if (start == end) {
            res = cnt;
            return;
        }

        checked[start] = true;
        for (int i = 0; i < relation[start].size(); i++) {
            int next = relation[start].get(i);
            if (!checked[next]) {
                dfs(next, end, cnt + 1);
            }
        }
    }

}
