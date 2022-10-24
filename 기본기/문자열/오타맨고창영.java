package 기본기.문자열;

import java.io.*;
import java.util.Scanner;

public class 오타맨고창영 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int index = sc.nextInt();
            StringBuilder sb = new StringBuilder(sc.next());
            // System.out.print(sb);
            sb.deleteCharAt(index - 1);
            System.out.println(sb);
        }
        sc.close();
    }
}
