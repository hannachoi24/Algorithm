package 기본기.문자열;

import java.io.*;
import java.util.*;

public class 팰린드롬수 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        String str = ""; // 입력값
        String res = ""; // 결과값 저장

        while (!(str.equals("0"))) { // 0이면 입력 그만 받기
            str = sc.nextLine();
            String reverse = new StringBuffer(str).reverse().toString(); // 입력받은 문자열 뒤집기
            if (str.equals("0"))
                continue; // 0이면 결과값 저장 안함
            else if (str.equals(reverse)) { // 입력값과 뒤집은 문자값이 같으면 결과 yes 출력
                res += "yes\n";
            } else {
                res += "no\n";
            }
        }
        System.out.println(res);
        sc.close();
    }
}
