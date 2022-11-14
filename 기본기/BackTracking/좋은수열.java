package 기본기.BackTracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 좋은수열 {
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        dfs("");
    }

    public static void dfs(String result) {
        if (result.length() == N) {
            System.out.println(result);
            System.exit(0); // 현재 실행하고 있는 프로세스를 강제 종료
        } else {
            for (int i = 1; i <= 3; i++) {
                if (isGoodSequence(result + i)) {
                    dfs(result + i);
                }
            }
        }
    }

    public static boolean isGoodSequence(String s) {
        int length = s.length() / 2;

        for (int i = 1; i <= length; i++) {
            if (s.substring(s.length() - i).equals(s.substring(s.length() - 2 * i, s.length() - i))) {
                return false;
            }
        }

        return true;
    }
}

/*
 * 길이가 N인 수열에서 인접하면서 동일한 수열이 있는 경우는 동일한 수열의 길이가 최소 1 부터 최대 N/2인 경우 발생한다.
 * 따라서 가장 마지막에 집어넣은 수 기준으로
 * 
 * 마지막 1개와 그 앞의 1개의 수가 동일한지
 * 마지막 2개와 그 앞의 2개의 수가 동일한지
 * 마지막 3개와 그 앞에 3개의 수가 동일한지
 * 
 * ....
 * 
 * 마지막 N/2개와 그 앞에 N/2개의 수가 동일한지 비교를 해
 *
 * 한 번이라도 동일한 경우가 생긴다면 그 수열은 나쁜 수열로 판단할 수 있다.
 * 가장 첫 번째로 나오는 백트래킹 알고리즘의 결과가 결과 중 가장 작은 수이기 때문에
 * 좋은 수열 중 가장 작은 수를 찾는 것은 문제가 되지 않는다. 그냥 첫 번째만 출력하면 된다.
 * System.exit(0) 을 이용하면 최초 출력 후 프로세스를 강제 종료할 수 있다.
 */