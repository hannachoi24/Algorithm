package 정렬;

import java.io.*;
import java.util.Arrays;
import java.util.Collections;

public class 수정렬하기4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Integer[] num = new Integer[Integer.parseInt(br.readLine())];

        for (int i = 0; i < num.length; i++) {
            num[i] = Integer.parseInt(br.readLine());
            Arrays.sort(num, Collections.reverseOrder());
            for (Integer in : num)
                bw.write(in + "\n");
            bw.flush();
        }
    }
}
