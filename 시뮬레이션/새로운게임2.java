package 시뮬레이션;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class 새로운게임2 {
    static int n, k;
    static int[][] map;
    static ArrayList<Integer>[][] list;
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { 1, -1, 0, 0 };
    static HashMap<Integer, Node> horse;

    public static class Node {
        int x, y, dir;

        public Node(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        list = new ArrayList[n][n];
        map = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                list[i][j] = new ArrayList<>();
            }
        }

        horse = new HashMap<>();

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int dir = Integer.parseInt(st.nextToken());
            horse.put(i + 1, new Node(x - 1, y - 1, dir - 1));
            list[x - 1][y - 1].add(i + 1);
        }

        int answer = 0;

        outer: while (++answer <= 1000) {

            for (int i = 1; i <= k; i++) {
                Node node = horse.get(i);

                ArrayList<Integer> up_horse = new ArrayList<>();
                int start_idx = 0;
                int x = node.x;
                int y = node.y;

                // 위에 있는 말 정보 얻기
                for (int p = 0; p < list[node.x][node.y].size(); p++) {
                    if (list[node.x][node.y].get(p) == i) {
                        start_idx = p;
                        break;
                    }
                }

                for (int p = start_idx; p < list[node.x][node.y].size(); p++) {
                    up_horse.add(list[node.x][node.y].get(p));
                }

                // 이동
                int nx = node.x + dx[node.dir];
                int ny = node.y + dy[node.dir];

                // 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다. (체스판을 벗어나는 경우에는 파란색과 같은 경우)
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 2) {
                    nx -= dx[node.dir];
                    ny -= dy[node.dir];
                    // 방향 변경
                    int dir = (node.dir % 2 == 0 ? node.dir + 1 : node.dir - 1);
                    nx += dx[dir];
                    ny += dy[dir];
                    node.dir = dir;

                    // 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 2) {
                        continue;
                    } else {
                        // 빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
                        if (map[nx][ny] == 1) {
                            for (int p = up_horse.size() - 1; p >= 0; p--) {
                                list[nx][ny].add(up_horse.get(p));
                                Node hh = horse.get(up_horse.get(p));
                                horse.put(up_horse.get(p), new Node(nx, ny, hh.dir));
                            }
                        } else {
                            for (Integer h : up_horse) {
                                list[nx][ny].add(h);
                                Node hh = horse.get(h);
                                horse.put(h, new Node(nx, ny, hh.dir));
                            }
                        }
                    }
                } else if (map[nx][ny] == 1) {
                    for (int p = up_horse.size() - 1; p >= 0; p--) {
                        list[nx][ny].add(up_horse.get(p));
                        Node hh = horse.get(up_horse.get(p));
                        horse.put(up_horse.get(p), new Node(nx, ny, hh.dir));
                    }
                } else if (map[nx][ny] == 0) {
                    for (Integer h : up_horse) {
                        list[nx][ny].add(h);
                        Node hh = horse.get(h);
                        horse.put(h, new Node(nx, ny, hh.dir));
                    }
                }

                if (list[nx][ny].size() >= 4) {
                    break outer;
                }

                // 말 빼기
                for (int p = list[x][y].size() - 1; p >= start_idx; p--) {
                    list[x][y].remove(p);
                }
            }
        }
        System.out.println(answer > 1000 ? -1 : answer);
    }
}