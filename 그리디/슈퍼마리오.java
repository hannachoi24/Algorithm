package 그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 슈퍼마리오 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sum = 0, diff = 100, answer = -1;

        for (int i = 0; i < 10; i++) {
            sum += Integer.parseInt(br.readLine());

            if (Math.abs(100 - sum) <= diff) { // 100에 가까운 수가 2개라면 큰 값을 선택하는건 비교 조건문에서 작거나 같은 경우
                diff = Math.abs(100 - sum); // 버섯의 점수를 누적하며 100과 최소 차가 나오는 경우 점수를 갱신해주면 된다.
                answer = sum;
            }
        }
        System.out.println(answer);
    }

}
