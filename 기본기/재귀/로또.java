package 기본기.재귀;

import java.util.*;
import java.io.*;

/*
입력으로 k개의 수를 주기 때문에, 그 k개의 수에서 6개를 골라 사전 순으로 출력하면 된다.
k개의 수에서 6개를 고르는 과정과 이를 사전 순으로 출력하는 과정 -> 백트래킹을 활용한 DFS
*/

public class 로또 {
    static int K;
    static int S[];
    static int result[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            K = Integer.parseInt(st.nextToken());

            if (K == 0) {
                break;
            }

            result = new int[K];
            S = new int[K];

            for (int i = 0; i < K; i++) {
                S[i] = Integer.parseInt(st.nextToken());
            }

            dfs(0, 0);

            System.out.println();
        }
    }

    private static void dfs(int start, int cnt) {
        if (cnt == 6) {
            for (int i = 0; i < K; i++) {
                if (result[i] == 1) {
                    System.out.print(S[i] + " ");
                }
            }
            System.out.println();
        }

        for (int i = start; i < K; i++) {
            result[i] = 1;
            dfs(i + 1, cnt + 1);
            result[i] = 0; // 출력하고 나서 다시 사용해야 하므로
        }
    }
}

/*
 * 입력에서 주어질 때부터 k개의 수가 오름차순으로 정렬되어 들어온다. 가장 먼저 각 수를 선택할 지 말지를 표시하는 배열(result[])을
 * 하나 만들어 둔다. (1 => 선택, 0 => 선택하지 않음) 이후 첫 번째 수부터 선택하고 다음 수를 호출한다. 그리고, 선택된 수가
 * 6개일 때 선택된 수들을 출력한다. 선택하고 호출하는 구조이므로 반드시 가장 먼저 첫 번째부터 마지막 수까지 모두 선택하게 되는데, 그
 * 과정에서 6개를 선택된 상황에서 출력을 한다. 수는 이미 정렬된 상태이므로 사전 순으로 가장 먼저 오는 순서를 출력하게 된다.
 * 
 * 핵심은 그 다음이다. 모든 수를 선택할 때까지 재귀호출이 반복되는데, 마지막 수의 선택이 끝나면 다시 해당 수를 0으로 셋팅해 선택하지
 * 않도록 바꿔준다. 예제에서 1, 2, 3, 4, 5, 6, 7의 경우 result[7] = 0을 하고 dfs(7,7) 재귀함수가 끝나면서
 * dfs(6,6)으로 돌아오는데, 이 때 result[6] = 0을 한 뒤 dfs(6,6)도 종료한다. dfs(5,5)가 돌아오면, 반복문을
 * 통해 result[7] = 1로 셋팅하고 result[6]=0인 상태에서 dfs(7, 6)을 호출하게 된다. dfs(7, 6)이 다시
 * 출력을 수행하면 1, 2, 3, 4, 5, 7을 출력하게 된다. 사전순으로 재귀함수의 특성을 활용해 출력하지 않을 문자 선택을 뒤에서부터
 * 하나씩 당기면서 출력을 수행한다.
 */