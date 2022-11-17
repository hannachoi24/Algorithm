package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 아기상어 {
    static int N;
    static int[][] map;
    static int[] dx = { -1, 0, 1, 0 }; // 북 서 남 동
    static int[] dy = { 0, 1, 0, -1 };
    static ArrayList<Node> fishes;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        map = new int[N][N];

        Queue<Node> q = new LinkedList<>(); // 아기상어 위치 넣을 공간(bfs 구현하니까 큐 사용)

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 9) { // 9는 아기상어의 위치
                    q.add(new Node(i, j, 0));
                    map[i][j] = 0;
                }
            }
        }

        int eat = 0;
        int time = 0;
        int size = 2;

        while (true) {
            LinkedList<Node> fish = new LinkedList<>(); // 먹을 수 있는 fish 담는 배열
            int[][] dist = new int[N][N]; // 새로운 위치 갱신하기위한 배열

            while (!q.isEmpty()) {
                Node current = q.poll(); // 현재 아기상어 위치

                for (int i = 0; i < 4; i++) {
                    int nx = current.x + dx[i];
                    int ny = current.y + dy[i];

                    // 칸을 이동할 수 있는 조건
                    // 물고기의 크기가 자신의 크기보다 작거나 같다면 이동시켜 준다.
                    // 현재 이동할 수 있는 곳으로 이동하면서 물고기의 크기가 자신의 크기보다 작으면 먹어주도록
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == 0 && map[nx][ny] <= size) {
                        dist[nx][ny] = dist[current.x][current.y] + 1;
                        q.add(new Node(nx, ny, dist[nx][ny]));

                        // 아기상어 크기 보다 작은 물고기 만나면 fish에 담아준다.
                        if (1 <= map[nx][ny] && map[nx][ny] <= 6 && map[nx][ny] < size) {
                            fish.add(new Node(nx, ny, dist[nx][ny]));
                        }
                    }
                }
            }

            if (fish.size() == 0) {
                System.out.println(time);
                return;
            }

            // 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
            // 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
            Node currentFish = fish.get(0);
            for (int i = 1; i < fish.size(); i++) {
                if (currentFish.dist > fish.get(i).dist) {
                    currentFish = fish.get(i);
                } // 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
                  // 위쪽 -> 왼쪽 좌표를 비교하며 우선순위에 맞게 먼저 먹을 물고기를 정해준다.
                else if (currentFish.dist == fish.get(i).dist) {
                    if (currentFish.x > fish.get(i).x)
                        currentFish = fish.get(i);
                    else if (currentFish.x == fish.get(i).x) {
                        if (currentFish.y > fish.get(i).y)
                            currentFish = fish.get(i);
                    }
                }
            }

            // 물고기가 있는 곳 까지 이동한 거리가 시간이 됨
            time += currentFish.dist;
            eat++;
            // 물고기를 먹었으면 그 칸은 빈칸이 된다.
            map[currentFish.x][currentFish.y] = 0;

            // 먹은 물고기수랑 아기상어 크기랑 같으면 아기상어의 크기는 1 증가
            if (eat == size) {
                size++;
                eat = 0;
            }
            q.add(new Node(currentFish.x, currentFish.y, 0)); // 물고기를 먹은 위치가 아기상어의 현재 위치이므로 갱신

        }
    }

    public static class Node {
        int x;
        int y;
        int dist;

        public Node(int x, int y, int dist) {
            // super();
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
}
