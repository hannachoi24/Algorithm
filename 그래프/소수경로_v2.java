package 그래프;

import java.util.*;
import java.io.*;

public class 소수경로_v2 {
    static boolean[] isNotPrime = new boolean[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(br.readLine());
        checkPrime();

        StringTokenizer st;
        for (int i = 0; i < tc; i++) {
            st = new StringTokenizer(br.readLine());
            int src = Integer.parseInt(st.nextToken());
            int answer = Integer.parseInt(st.nextToken());

            sb.append(bfs(src, answer) + '\n');
        }
        System.out.println(sb.toString());
    }

    static String bfs(int src, int answer) {
        Queue<Integer> q = new LinkedList<>();
        Map<Integer, Integer> map = new HashMap<>();

        map.put(src, 0);
        q.add(src);

        while (!q.isEmpty()) {
            int pos = q.poll();
            int move = map.get(pos);

            if (pos == answer) {
                return move + "";
            }

            int[] pNum = { pos / 1000, (pos / 100) % 10, (pos / 10) % 10, pos % 10 };

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i == 0 && j == 0)
                        continue; // 1000 이상 조건

                    int tmp = pNum[i];
                    pNum[i] = j;
                    int next = changePassword(pNum);
                    pNum[i] = tmp;

                    if (isNotPrime[next])
                        continue;

                    if (!map.containsKey(next)) {
                        q.add(next);
                        map.put(next, move + 1);
                    }
                }
            }
        }
        return "impossible";
    }

    static int changePassword(int[] pNum) {
        int num = 0;
        for (int i = 0; i < 4; i++) {
            num += pNum[i] * (Math.pow(10, 3 - i));
        }
        return num;
    }

    static void checkPrime() {
        for (int i = 2; i < 10000; i++) {
            if (!isNotPrime[i]) {
                for (int j = i * i; j < 10000; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }
    }
}

/*
 * ex) 초기값으로 0000이 되어있는 네개의 칸이 있으면 그것을 한 방향으로 돌려서 자신이 설정한 비밀번호(8012)로 이동해야 한다.
 * 
 * 문제의 조건에 맞게 한 칸을 설정하는 데 한 번의 움직임을 사용한다고 하자.
 * 
 * 1) 첫 번째 칸 : 0 →8 로 움직인다. (움직임 +1)
 * 
 * 2) 두 번째 칸 : 0 → 0 제자리 그대로 냅둔다.
 * 
 * 3) 세 번째 칸 : 0 → 1 로 움직인다. (움직임 +1)
 * 
 * 4) 네 번째 칸 : 0 → 2 로 움직인다. (움직임 +1)
 * 
 * ☛ 그래서 총 최소로 걸린 움직임은 3이다.
 */