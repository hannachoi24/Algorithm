package 기본기.BackTracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 가르침 {
    static int N, K;
    static String[] word;
    static boolean[] visit;
    static int max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        word = new String[N];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            str = str.replace("anta", "");
            str = str.replace("tica", "");
            word[i] = str;
        }

        if (K < 5) { // a c i n t의 개수가 5개이므로
            System.out.println("0");
            return;
        } else if (K == 26) { // 모든 알파벳을 다 읽을 수 있다.
            System.out.println(N);
            return;
        }

        visit = new boolean[26]; // 각 알파벳을 배웠는지 체크
        visit['a' - 'a'] = true; // visit[0] = true
        visit['c' - 'a'] = true; // visit[2] = true
        visit['i' - 'a'] = true; // visit[8] = true
        visit['n' - 'a'] = true; // visit[13] = true
        visit['t' - 'a'] = true; // visit[19] = true

        dfs(0, 0);

        System.out.println(max);
    }

    public static void dfs(int alpha, int len) {
        if (len == K - 5) { // a c i n t의 개수가 5개이므로
            int cnt = 0;
            for (int i = 0; i < N; i++) { // 뽑은 알파벳으로 몇개의 단어를 읽을 수 있는지 카운트
                boolean read = true;
                for (int j = 0; j < word[i].length(); j++) {
                    if (!visit[word[i].charAt(j) - 'a']) {
                        read = false;
                        break;
                    }
                }
                if (read)
                    cnt++;
            }
            max = Math.max(max, cnt);
            return;
        }

        for (int i = alpha; i < 26; i++) {
            if (visit[i] == false) {
                visit[i] = true;
                dfs(i, len + 1);
                visit[i] = false;
            }
        }
    }
}
