package 완전탐색;

import java.io.*;
import java.util.*;

public class 단어나누기 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();

        char[] arr = str.toCharArray();

        // 세개의 구간으로 쪼개기 때문
        int[] slice = new int[2];

        // 정렬된 결과를 저장하기 위한 list
        ArrayList<String> list = new ArrayList<>();

        for (int i = 0; i < arr.length - 1; i++) {
            slice[0] = i;
            for (int j = i + 1; j < arr.length - 1; j++) {
                slice[1] = j;

                String s1 = str.substring(0, slice[0] + 1);
                String s2 = str.substring(slice[0] + 1, slice[1] + 1);
                String s3 = str.substring(slice[1] + 1, arr.length);

                String newStr = "";

                StringBuffer strBuf = new StringBuffer();
                strBuf.append(s1);
                newStr += strBuf.reverse();

                strBuf = new StringBuffer();
                strBuf.append(s2);
                newStr += strBuf.reverse();

                strBuf = new StringBuffer();
                strBuf.append(s3);
                newStr += strBuf.reverse();

                list.add(newStr);
            }
        }

        Collections.sort(list);

        System.out.println(list.get(0));
    }

}
