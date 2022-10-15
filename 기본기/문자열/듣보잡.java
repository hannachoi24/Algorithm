package 기본기.문자열;

import java.io.*;
import java.util.*;

/*
듣도 못한 사람의 수를 set에다 저장한 뒤, 보도 못한 사람이 그 set에 들어있는지를 확인해서 들어있다면 출력한다.
ArrayList로 contains()를 사용할 수도 있지만, 시간초과가 발생한다. 시간초과를 잡기 위해서는 HashSet을 사용해야한다.
*/

public class 듣보잡 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < N; i++) {
            set.add(br.readLine());
        }

        ArrayList<String> result = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            String tmp = br.readLine();
            if (set.contains(tmp)) {
                result.add(tmp);
            }
        }
        Collections.sort(result); // 사전순 출력

        System.out.println(result.size());
        for (String s : result) {
            System.out.println(s);
        }
    }
}
