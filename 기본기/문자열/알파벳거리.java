package 기본기.문자열;

import java.io.IOException;
import java.util.Scanner;

public class 알파벳거리 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            String str1 = sc.next();
            String str2 = sc.next();
            int[] arr = new int[str1.length()];
            for (int j = 0; j < str1.length(); j++) {
                if (str2.charAt(j) >= str1.charAt(j)) {
                    arr[j] = str2.charAt(j) - str1.charAt(j);
                } else {
                    arr[j] = str2.charAt(j) - str1.charAt(j) + 26;
                }
            }
            System.out.print("Distances: ");
            for (int j = 0; j < arr.length; j++) {
                System.out.print(arr[j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
