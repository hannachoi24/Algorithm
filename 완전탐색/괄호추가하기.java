package 완전탐색;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.*;

public class 괄호추가하기 {
    static int n, result;
    static char[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new char[n];
        arr = br.readLine().toCharArray();
        result = Integer.MIN_VALUE;

        // 2번 인덱스의 숫자 (2번째 숫자)부터 괄호를 내 왼쪽에 칠건지(결국 안치는게 됨) 오른쪽에 칠건지 치지 않을건지
        solve(2, arr[0] - '0');
        System.out.println(result);
    }

    private static void solve(int i, int sum) {
        if (i >= n) {
            result = Math.max(result, sum);
            return;
        }
        // 괄호 안 친 경우 지금까지의 합과 나를 계산한 결과를 다음 숫자 (index는 +2)에 넘긴다
        solve(i + 2, cal(sum, arr[i] - '0', arr[i - 1]));

        // 오른쪽에 괄호 친 경우
        if (i + 2 < n) {
            // 옆 괄호 먼저 계산
            int right = cal(arr[i] - '0', arr[i + 2] - '0', arr[i + 1]);
            // 지금까지 결과와 합하기
            int left = cal(sum, right, arr[i - 1]);
            solve(i + 4, left);
        }
    }

    private static int cal(int i, int j, char op) {
        if (op == '+')
            return i + j;
        else if (op == '-')
            return i - j;
        else
            return i * j;
    }
}

/*
 * 수식을 계산할 때 두 가지의 경우가 있다. 괄호를 추가하거나, 추가하지 않거나.
 * 
 * 인덱스 기준으로 2에 위치하는, 그러니까 두 번째 숫자부터 시작하여 괄호를 추가하지 않거나 (현재까지의 결과와 계산하는 경우), 추가하거나
 * (현재까지의 결과와 계산하기 전에 오른쪽 숫자와 괄호를 치는 경우)로 나누어 계산하면 된다.
 * 
 * 모든 경우를 다 구해 보고 최댓값을 구하게 된다.
 * 
 * solve 함수에 첫번째 인자는 현재 숫자의 인덱스값이고, 두번째 값은 현재까지의 결과다. 처음 시작할 때는 현재까지의 결과를 첫번째
 * 숫자로 넣어준다. 괄호를 추가하지 않는다면 그냥 첫번째 숫자와 직전의 연산자로 계산하고, 추가한다면 그 과정 전에 오른쪽에 있는 숫자와
 * 직후의 연산자로 계산하는 과정을 거친다.
 */