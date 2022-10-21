package 기본기.문자열;

import java.util.Scanner;

public class 첫글자를대문자로 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();

            System.out.println((str.charAt(0) + "").toUpperCase() + str.substring(1, str.length()));
        }
        sc.close();
    }
}
