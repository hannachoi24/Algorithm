package TwoPointer;

import java.io.*;
import java.util.*;

public class 수들의합2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int s = 0, e = 0, sum = 0, cnt = 0; // s: 시작점, e: 끝점, cnt: 경우의 수
        while (true) {
            if (sum >= M) { // 아직 탐색할 구간이 남았으므로 s의 값을 이동해주면서 구간 탐색을 더해준다.
                sum -= arr[s++]; // e의 값을 조정하면 값이 더욱 커지기 때문에 s의 값을 이동해서 앞에 있는 원소들을 하나씩 빼준다.
            } else if (e == N)
                break;
            else { // 더 이상 탐색해봤자 sum보다 큰 값은 안나오므로 반복문을 종료해주면 된다.
                sum += arr[e++];
            }
            if (sum == M) {
                cnt++;
            }
        }
        System.out.println(cnt);

    }
}
