package TwoPointer;

import java.io.*;
import java.util.*;

public class 소수의연속합 {
    static int N;
    static List<Integer> list;
    static boolean[] isPrime;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        list = new ArrayList<>();
        makePrime();

        int start = 0, end = 0, sum = 0, cnt = 0;

        while (start <= end && end < list.size()) {
            if (sum < N) {
                sum += list.get(end++);
            } else {
                if (sum == N) {
                    cnt++;
                }
                sum -= list.get(start++);
            }
        }
        System.out.println(cnt);
    }

    static void makePrime() {
        isPrime = new boolean[N + 1];
        Arrays.fill(isPrime, true);

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (isPrime[i]) {
                list.add(i);
            }
        }
        list.add(0); // 투 포인터 탐색할 때 끝 인덱스까지 탐색하기 위함
    }
}

/*
 * 1. 에라토스테네스의 체를 사용하여 n범위 안에 있는 소수를 구하여 저장한다.
 * 1-1. 마지막에 0을 더 추가한 이유는 투 포인터 탐색할 때 끝 인덱스까지 탐색하기 위함이다.
 * 2. 투 포인터를 사용하여 n과 일치하는 연속된 부분합의 갯수를 구한다.
 * 2-1. sum < n, 수가 작으므로 end 인덱스의 값을 더해준다.
 * 2-2. sum >= n, 수가 크므로 start 인덱스의 값을 빼준다. n과 같으면 카운트해준다.
 */
