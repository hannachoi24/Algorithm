package 기본기.문자열;

import java.io.IOException;
import java.util.*;

public class 문자열_9086 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            String str = sc.next();
            System.out.println(str.charAt(0) + "" + str.charAt(str.length() - 1));
        }
        sc.close();
    }
}
