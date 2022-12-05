package 시뮬레이션;

import java.util.*;
import java.io.*;

class Tree implements Comparable<Tree> {
    int x, y, age;

    public Tree(int x, int y, int age) {
        super();
        this.x = x;
        this.y = y;
        this.age = age;
    }

    @Override
    public int compareTo(Tree o) {
        return this.age - o.age;
    }
}

public class 나무재테크 {
    static int N, M, K; // N: 맵의 크기, M: 나무의 개수, K: K년이 지난 후
    static int A[][]; // 추가되는 양분의 양
    static int eat[][]; // 해당 칸의 양분 양
    static int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        A = new int[N + 1][N + 1];
        eat = new int[N + 1][N + 1]; // 양분
        Deque<Tree> list = new LinkedList<>(); // 나이가 어린 나무부터 양분을 먹는것을 addFirst로 처리해주기 위해 Deque 사용

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
                eat[i][j] = 5;
            }
        }

        // 나무 리스트에 추가
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()); // 나무의 위치
            int y = Integer.parseInt(st.nextToken()); // 나무의 위치
            int treeAge = Integer.parseInt(st.nextToken()); // 나무의 나이
            list.add(new Tree(x, y, treeAge));
        }

        while (K > 0) {
            Queue<Tree> dieTree = new LinkedList<>();

            // 봄
            for (int i = 0; i < list.size();) {
                Tree cur = list.poll();
                // 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
                if (eat[cur.x][cur.y] >= cur.age) {
                    eat[cur.x][cur.y] -= cur.age;
                    cur.age++;
                    i++;
                    list.add(cur);
                    // 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
                } else {
                    dieTree.add(cur);
                }
            }

            // 여름 (봄에 죽은 나무가 양분으로 변하게 된다.)
            for (Tree t : dieTree) {
                eat[t.x][t.y] += t.age / 2;
            }

            // 가을 (나무가 번식한다.)
            // 번식하는 나무는 나이가 5의 배수이어야 하며
            Queue<Tree> breeding_list = new LinkedList<>();
            for (Tree t : list) {
                if (t.age % 5 == 0) {
                    breeding_list.add(t);
                }
            }

            // 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
            while (!breeding_list.isEmpty()) {
                Tree t = breeding_list.poll();

                for (int i = 0; i < 8; i++) {
                    int nx = t.x + dx[i];
                    int ny = t.y + dy[i];

                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                        list.addFirst(new Tree(nx, ny, 1)); // 나이가 어린 나무부터 양분 먹는것을 처리해주기 위해 Deque에 addFirst
                    }
                }
            }

            // 겨울 (땅을 돌아다니면서 땅에 양분을 추가)
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    eat[i][j] += A[i][j];
                }
            }

            K--;
        }

        bw.write(list.size() + "\n");
        bw.flush();
        bw.close();
    }
}

/*
 * 주의할 점!!
 * list를 도는 for문 안에서 list를 변경하지 말 것
 * 추가/삭제가 많을 땐 LinkedList, 검색이 많을 땐 ArrayList를 사용할 것
 * sort 하는 방법 외에 다른 방법 생각해 볼 것
 */