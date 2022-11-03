package 정렬;

import java.util.*;

public class 중복빼고정렬하기_TreeSet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // 중복값을 받지 않고 자동정렬을 위해 TreeSet사용
        TreeSet<Integer> set = new TreeSet<Integer>();

        // 입력 시 자동으로 중복값을 제거
        for (int i = 0; i < n; i++) {
            set.add(sc.nextInt());
        }

        // 동작 속도 향상을 위해 StringBuilder 사용
        StringBuilder sb = new StringBuilder();
        for (int i : set) {
            sb.append(i).append(" ");
        }
        System.out.println(sb.toString());
        sc.close();
    }
}
