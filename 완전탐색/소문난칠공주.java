package 완전탐색;

import java.util.*;

public class 소문난칠공주 {
    static char map[][] = new char[5][5];
    static int dx[] = { -1, 1, 0, 0 };
    static int dy[] = { 0, 0, -1, 1 };
    static int combX[] = new int[25];
    static int combY[] = new int[25];
    static int ans = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            map[i] = sc.next().toCharArray();
        }

        // 좌표 미리 계산
        for (int i = 0; i < 25; i++) {
            combX[i] = i % 5;
            combY[i] = i / 5;
        }

        combination(new int[7], 0, 0, 7);
        System.out.println(ans);
    }

    public static void combination(int[] comb, int idx, int depth, int left) {
        if (left == 0) {
            bfs(comb);
            return;
        }

        if (depth == 25)
            return;

        comb[idx] = depth;
        combination(comb, idx + 1, depth + 1, left - 1); // 선택한 경우
        combination(comb, idx, depth + 1, left); // 선택하지 않은 경우
    }

    public static void bfs(int comb[]) {
        Queue<Integer> q = new LinkedList<>();
        boolean visited[] = new boolean[7];

        visited[0] = true;
        q.add(comb[0]);
        int cnt = 1, sCnt = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();
            if (map[combY[cur]][combX[cur]] == 'S')
                sCnt++;

            for (int i = 0; i < 4; i++) {
                for (int next = 1; next < 7; next++) {

                    if (!visited[next] && combX[cur] + dx[i] == combX[comb[next]]
                            && combY[cur] + dy[i] == combY[comb[next]]) {
                        visited[next] = true;
                        q.add(comb[next]);
                        cnt++;
                    }
                }
            }
        }

        // 7개 모두 연결되어 있다면
        if (cnt == 7) {
            if (sCnt >= 4) {
                ans++;
            }
        }

    }
}

/*
 * 이 문제는 단순히 BFS, DFS를 사용하면 해결하기 매우 힘들다. 모든 자리에서 4방향을 모두 조사하는 식으로 탐색하면 경우의 수가 너무
 * 많아 시간 초과가 발생한다. 따라서 조합을 사용하여 해결하는 편이 좋다.
 *  
 * 25개의 자리 중 7개를 선택하는 경우의 수는 25C7 = 480700 으로 작은 편이다. 
 *  
 * 1. 25개의 자리 중 7개를 뽑는다.
 * 2. 해당 7개의 자리가 모두 상하좌우로 연결되어 있는지 확인한다(DFS 혹은 BFS 사용)
 * 3. 'S'가 4개 이상 포함되는지 확인한다.
 *  
 * 위와 같은 과정을 통해 문제를 해결할 수 있다. 이때 자리는 25개로 고정이므로 25개의 자리 중 7을 뽑는 것은 0~24의 숫자 중
 * 7개를 뽑는 것으로 생각해도 편하다. 이렇게 1차원 숫자로 뽑은 뒤, 미리 X좌표와 Y좌표를 계산해 놓은 배열을 이용하면 편하다.
 * 
 * 예를 들어, 13번 자리를 뽑았다고 하자. 미리 0~24의 숫자로 좌표를 계산해놓은 배열 combX[], combY[]를 이용하면,
 *  
 * combX[13] = 2;
 * combY[13] = 3;
 *  
 * 이렇게 좌표를 구할 수 있다.
 *  
 * 이후 일반적인 조합을 구현하는 함수를 통해 25개의 자리 중 7개를 선택했다면, bfs 탐색을 통해 자리가 모두 이어져있는지 확인한다. 
 *  
 * 이때 상하좌우 4방향을 모두 조사하면서 7개의 자리 중 하나라도 있는지 확인하는 식으로 탐색하면 된다. bfs 탐색을 하면서 'S'의
 * 개수도 세주면 된다.
 */
