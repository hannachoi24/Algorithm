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
                                Node hh = horse.get(up_horse.get(p)); // 위에 있는 말의 번호에 해당하는 값(위치, 방향)들을 horse에서 가져온다.
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
                } else if (map[nx][ny] == 1) { // 이동한 칸이 빨간색이라면
                    for (int p = up_horse.size() - 1; p >= 0; p--) {
                        list[nx][ny].add(up_horse.get(p));
                        Node hh = horse.get(up_horse.get(p));
                        horse.put(up_horse.get(p), new Node(nx, ny, hh.dir));
                    }
                } else if (map[nx][ny] == 0) { // 이동한 칸이 흰색이라면
                    for (Integer h : up_horse) {
                        list[nx][ny].add(h);
                        Node hh = horse.get(h);
                        horse.put(h, new Node(nx, ny, hh.dir));
                    }
                }

                // 이동하면서 말을 쌓다가 말이 4개이상이 쌓이면 턴 종료
                if (list[nx][ny].size() >= 4) {
                    break outer;
                }

                // 이동시킨 후 원래 말이 있던 x, y 위치에서의 말 ~ 그 위에 쌓은 말의 정보를 제거
                for (int p = list[x][y].size() - 1; p >= start_idx; p--) {
                    list[x][y].remove(p);
                }
            }
        }
        System.out.println(answer > 1000 ? -1 : answer);
    }
}

/*
 * HashMap을 활용해서 key에 말의 번호, value는 말에 대한 정보(위치 x, y, 방향)을 객체에 넣어 관리한다.
 * ArrayList<>인 2차원 배열로 체스판을 관리한다. 체스판 안에는 말의 번호를 넣어서 관리한다.
 * 각 턴에서 말번호 1번부터 이동을 처리한다. 말이 이동할 때 말 위에 같이 있는 말들도 이동을 하는 것을 주의해서 구현한다. 어떤 말 위에
 * 1번말이 놓여져 있을 수도 있으므로 해당 map에서 각 말이 있는 위치 ~ 그 위에 쌓아진 말들을 up_horse라는 ArrayList에
 * 넣어 관리한다.
 * 만약 말의 방향대로 움직임을 처리했는데 범위를 넘거나 파란영역이라면 방향을 변경한다. 그리고 이동한 곳이 또 격자판을 넘거나 파란 곳이라면
 * 방향을 반대로 변경한 후 그 자리에 위치시키도록 한다.
 * 또한 이동한 곳이 빨간 영역이라면 up_horse를 끝부터 , 하얀 영역이라면 0번인덱스부터 차례대로 해당 영역에 넣어주고 hash맵에
 * 저장된 말의 정보도 같이 갱신시켜준다.
 * 그리고 이동시킨 후 원래 말이 있던 x, y 위치에서 말 ~ 그 위에 쌓은 말의 정보를 제거한다.
 * 만약 이동하면서 말을 쌓다가 말이 4개이상이 쌓이면 턴은 종료시킨다.
 */