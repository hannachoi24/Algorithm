package 기본기.BackTracking;

import java.util.*;
import java.io.*;

/*
투포인트 알고리즘, DFS 활용 하여 해결 할 수 있다. 
DFS 알고리즘을 적용하여 지금 위치의 원소를 선택하거, 선택하지 않거나 2가지 조건을 재귀함수로 계속 호출
*/

public class 부분수열의합 {
    static int N, S, count = 0; // N: 정수 개수, S: 선택한 부분수열의 원소를 다 더한 값, count: S가 되는 경우의 수
    static int[] arr; // 입력 받은 부분수열을 담을 배열

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        S = sc.nextInt();
        arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        dfs(0, 0);

        /*
         * 공집합을 제외!
         * 공집합은 아무것도 없는 경우라서 합이 0이 나온다. 그러면 항상 dfs(index+1, sum) 이 함수만 선택하면 합이 0이 나올 것.
         * 그래서 문제에서 구하라고 하는 합이 0일 때만 공집합의 합을 빼준다.
         */
        if (S == 0) {
            count--;
            System.out.println(count);
        } else {
            System.out.println(count);
        }
    }

    private static void dfs(int index, int sum) {
        if (index == N) { // dfs로 돌며 누적시키다가 위치를 나타내는 index가 마지막 위치로 오면 원하는 값인지 아닌지 체크 하고 count
            if (sum == S) {
                count++;
            }
            return;
        }

        // 부분수열에서 지금 위치의 원소를 선택하거나, 선택하지 않거나
        dfs(index + 1, sum + arr[index]); // 지금 위치의 원소를 선택
        dfs(index + 1, sum); // 선택 하지 않음
    }
}
