package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
가장 작은 수가 나올려면 작은 수에서 큰 수를 빼면 된다.

그래서 '-' 를 기준으로 나누고, '+'이 포함된 식은 모두 더해준다. 

그리고 앞의 수에서 뒤의 수를 빼주면 된다.
*/

public class 잃어버린괄호 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] exp = br.readLine().split("-");
        int answer = 0;

        for (int i = 0; i < exp.length; i++) {
            int sum = 0;
            if (exp[i].contains("+")) {
                String[] nums = exp[i].split("\\+");
                for (int j = 0; j < nums.length; j++) {
                    sum += Integer.parseInt(nums[j]);
                }
            } else
                sum += Integer.parseInt(exp[i]);

            answer = i == 0 ? sum : answer - sum;
        }

        System.out.println(answer);
    }
}