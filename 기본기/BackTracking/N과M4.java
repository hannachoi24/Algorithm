package 기본기.BackTracking;

import java.io.*;
import java.util.*;

/*
'비내림차순'이므로 중복도 허용이 된다는 것이다. 반복문 내에서 i 값을 1 더하여 재귀호출을 해주는 것(오름차순)이 아닌 
그냥 i 값을 인자로 넘겨 재귀호출 해주면 된다.
즉, 우리가 수정할 값은 dfs 재귀호출 시에 넘겨줄 인자만 바꿔주면 된다!
*/

public class N과M4 {
    static int N, M;
    static int arr[];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];

        dfs(1, 0);

        System.out.println(sb);
    }

    public static void dfs(int start, int depth) {
        if (depth == M) {
            for (int val : arr) {
                sb.append(val).append(' ');
            }
            sb.append('\n');
            return;
        }

        for (int i = start; i <= N; i++) {
            arr[depth] = i;
            dfs(i, depth + 1);
        }
    }
}
