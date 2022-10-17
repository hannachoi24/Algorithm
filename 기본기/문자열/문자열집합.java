package 기본기.문자열;

import java.io.*;
import java.util.*;

public class 문자열집합 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int cnt = 0;

        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            map.put(br.readLine(), 1);
        }

        for (int j = 0; j < M; j++) {
            String str = br.readLine();
            if (map.get(str) != null) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
