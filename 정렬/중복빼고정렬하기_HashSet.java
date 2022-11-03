package 정렬;

import java.util.*;

public class 중복빼고정렬하기_HashSet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // 중복값을 받지 않기 위해 HashSet사용
        HashSet<Integer> set = new HashSet<Integer>();

        // 입력 시 자동으로 중복값을 제거
        for (int i = 0; i < n; i++) {
            set.add(sc.nextInt());
        }

        // 입력값 받은 HashSet을 ArrayList로 담은 뒤, Collections.sort()를 이용해 오름차순 정렬
        ArrayList<Integer> list = new ArrayList<Integer>(set);
        Collections.sort(list);

        // 동작 속도 향상을 위해 StringBuilder 사용
        StringBuilder sb = new StringBuilder();
        for (int i : list) {
            sb.append(i).append(" ");
        }
        System.out.println(sb.toString());
        sc.close();
    }
}
