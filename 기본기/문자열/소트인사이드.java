package 기본기.문자열;

import java.io.*;
import java.util.*;

public class 소트인사이드 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] arr = br.readLine().toCharArray(); // toCharArray(): 하나의 문자열을 각 자리의 문자(아스키값)으로 변환하여 char[] 배열로 만들어주는 방법

        Arrays.sort(arr); // 오름차순 정렬

        // 오름차순으로 정렬된 arr을 뒤에서부터 출력해주면 내림차순 정렬
        for (int i = arr.length - 1; i >= 0; i--) {
            System.out.print(arr[i]);
        }
    }
}
