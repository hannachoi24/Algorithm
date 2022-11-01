package 기본기.BackTracking;

import java.io.*;
import java.util.*;

/*
N과 M 을 함수 인자로 안넘겨도 된다. N과 M은 자체 값이 변경되지 않고 재귀와 반복문의 조건으로써만 쓰이기 때문에 전역변수로 바꾸어도 무방하다. 
자바에서는 static이라는 정적 키워드를 이용하여 전역변수처럼 활용할 수 있다. 
main 메소드는 static 메소드라 정적 메소드에서 외부 변수를 쓰려면 해당 변수 또한 정적 변수여야 하기 때문에 
main 밖의 변수 또한 static이 붙는다. 그래서 혼용하여 쓰기 때문에 정적변수 = 전역변수 라고 생각하고 읽도록 하자 
*/

public class N과M1_전역변수 {
    static int N;
    static int M;
    static int[] arr; // 결과를 담을 배열
    static boolean[] visit; // 중복체크를 위한 방문 배열
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];
        visit = new boolean[N];

        // 정적변수를 쓰면 되기 때문에 굳이 N과 M을 넘겨줄 필요 없다.
        dfs(0);

        System.out.println(sb);
    }

    public static void dfs(int depth) {
        if (depth == M) {
            for (int val : arr) {
                sb.append(val).append(' ');
            }
            sb.append('\n');
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!visit[i]) {
                visit[i] = true;
                arr[depth] = i + 1; // 해당 깊이를 index로 하여 i + 1 값 저장
                dfs(depth + 1); // 다음 자식 노드 방문을 위해 depth 1 증가시키면서 재귀호출
                visit[i] = false;
            }
        }
    }
}
