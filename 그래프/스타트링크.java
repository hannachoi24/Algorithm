package 그래프;

import java.io.*;
import java.util.*;

public class 스타트링크 {
    static int F, S, G, U, D; // 건물 총 높이, 출발지, 목적지, 방향 위, 방향 아래
    static int[] move;
    static int[] dir = new int[2]; // 방향 배열

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        F = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        G = Integer.parseInt(st.nextToken());
        dir[0] = Integer.parseInt(st.nextToken());
        dir[1] = -Integer.parseInt(st.nextToken());

        move = new int[F + 1];

        bfs(S);
    }

    static void bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visit = new boolean[F + 1];

        q.add(start);
        visit[start] = true;
        move[start] = 0;

        while (!q.isEmpty()) {
            int pos = q.poll();
            if (pos == G) {
                System.out.println(move[pos]);
                return;
            }

            for (int i = 0; i < 2; i++) {
                int next = pos + dir[i];

                if (next > F || next < 1)
                    continue;

                if (!visit[next]) {
                    visit[next] = true;
                    q.add(next);
                    move[next] = move[pos] + 1;
                }
            }
        }

        System.out.println("use the stairs");
    }
}
