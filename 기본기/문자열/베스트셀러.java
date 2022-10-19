package 기본기.문자열;

import java.io.*;
import java.util.*;

public class 베스트셀러 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        Map<String, Integer> map = new TreeMap<>(); // 자동 정렬 되기 때문에 treemap 사용

        for (int i = 0; i < N; i++) {
            String str = br.readLine();

            if (map.containsKey(str)) { // 팔린 책 개수를 value로 두고 count
                map.put(str, map.get(str) + 1);
            } else {
                map.put(str, 1);
            }
        }

        List<Map.Entry<String, Integer>> entryList = new LinkedList<>(map.entrySet()); // map을 value 기준으로 정렬하기 위해 List로
                                                                                       // 변형
        entryList.sort((o1, o2) -> o2.getValue() - o1.getValue()); // 내림차순으로 sort

        System.out.println(entryList.get(0).getKey()); // 정렬한 리스트의 첫 번째 인덱스의 key 값이 찾는 답
    }
}
