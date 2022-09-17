package 그래프;

import java.util.*;

public class 토마토_7569 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] dx = { -1, 0, 1, 0, 0, 0 };
        int[] dy = { 0, 1, 0, -1, 0, 0 };
        int[] dz = { 0, 0, 0, 0, 1, -1 };

        int M = sc.nextInt(); // 가로
        int N = sc.nextInt(); // 세로
        int H = sc.nextInt(); // 높이

        int[][][] board = new int[H + 1][N + 1][M + 1];
        int cnt = 0;
        int days = 0;
        Queue<int[]> q = new LinkedList<>();

        // 토마토 판 입력
        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= N; j++)
                for (int k = 1; k <= M; k++) {
                    board[i][j][k] = sc.nextInt();
                    // 토마토가 익었다면 큐에 넣기
                    if (board[i][j][k] == 1)
                        q.add(new int[] { i, j, k });
                    // 토마토가 안 익은게 있다면 cnt++
                    else if (board[i][j][k] == 0)
                        cnt++;
                }

        while (cnt > 0 && !q.isEmpty()) {
            for (int s = q.size(); s > 0; s--) {
                int[] cur = q.poll();
                int x = cur[0];
                int y = cur[1];
                int z = cur[2];

                for (int i = 0; i < 6; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    int nz = z + dz[i];

                    if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H || board[nx][ny][nz] != 0)
                        continue;

                    cnt--;
                    board[nx][ny][nz] = 1;
                    q.add(new int[] { nx, ny, nz });
                }
            }
            days++;
        }
        System.out.println(cnt == 0 ? days : -1);
    }
}

/*
 * 익은 토마토가 주변의 앞, 뒤, 왼쪽, 오른쪽 4방향의 안익은 토마토를 익게 만드는 총 일수를 구하는 문제이다. 전형적인 BFS 문제의
 * 구조를 띄고 있다.
 * 
 * 처음 입력을 받으며 익은 토마토는 Queue에 넣는다.나의 경우 Queue에 int[] 배열로 토마토의 위치를 저장하였다.
 * 
 * 마지막에 안익은 토마토가 존재할 경우 -1을 출력하는 조건 존재하기 때문에 이를 처리하기 위해 안익은 토마토가 등장할 경우 숫자를 카운트
 * 해준다.
 * 
 * Queue에서 하나씩 poll하며 4방향 탐색을 하며, 익지 않은 토마토(0)가 존재할 경우 익은 토마토(1)로 변경한다. 이렇게 하면
 * visit처리를 해주지 않고도 다시 탐색을 하지 않도록 막을 수 있다.
 * 이 문제에서는 토마토가 모두 익게 되는 최소 날짜를 구해야 하는데 한 Queue에 들어가 모두 비워지는 경우가 하루이다.
 * 위와 같이 Queue에 몇 개의 토마토가 들어갔던 Queue가 모두 비워지는 경우는 하루이다.
 * 
 * 따라서, Queue에 값을 추가할 때, 다른 Queue나 List에 값을 넣은 다음 Queue가 비워졌을 때 기존의 Queue에 모두
 * 추가해주는 방법도 있다. 그리고, for문을 통해 Queue의 size만큼 돌게 되면 하루만큼 경과하기 때문에 이러한 방식으로 문제를
 * 풀어보았다.
 */
