package 완전탐색;

import java.io.*;
import java.util.*;

public class Doubles {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int input = 1;

        while (true) {
            ArrayList<Integer> arr = new ArrayList<Integer>();

            input = sc.nextInt();

            if (input == -1)
                break;

            arr.add(input);

            while ((input = sc.nextInt()) != 0) {
                arr.add(input);
            }

            int cnt = 0;

            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr.size(); j++) {
                    if (i == j)
                        continue;

                    if (arr.get(i) == arr.get(j) * 2)
                        cnt++;
                }
            }

            System.out.println(cnt);

        }

        sc.close();
    }
}
