package 시뮬레이션;

import java.io.*;
import java.util.*;

public class 기적의매매법 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int money = sc.nextInt();
        int[] chart = new int[14];

        for (int i = 0; i < 14; i++) {
            chart[i] = sc.nextInt();
        }

        int hyeonResult = BNP(chart, money);
        int minResult = TIMING(chart, money);

        if (hyeonResult > minResult) {
            System.out.println("BNP");
        } else if (hyeonResult < minResult) {
            System.out.println("TIMING");
        } else {
            System.out.println("SAMESAME");
        }
        sc.close();
    }

    static int BNP(int[] chart, int money) {
        int cnt = 0; // 주식 수

        for (int i = 0; i < 14; i++) {
            // 주식 매수
            if (money >= chart[i]) {
                cnt += money / chart[i]; // 주식 수 계산
                money = money % chart[i]; // 현재 남은 현금
            }
        }
        return money + cnt * chart[13]; // 1월 14일의 자산은 (현금 + 1월 14일의 주가 × 주식 수)
    }

    static int TIMING(int[] chart, int money) {
        int cnt = 0; // 주식 수
        int upCnt = 0; // 주가 상승 횟수
        int downCnt = 0; // 주가 하락 횟수
        int yesterday = chart[0];

        for (int i = 1; i < 14; i++) {
            int today = chart[i];

            if (today > yesterday) {
                upCnt++;
                downCnt = 0;
            } else if (today < yesterday) {
                downCnt++;
                upCnt = 0;
            } else {
                upCnt = 0;
                downCnt = 0;
            }

            if (upCnt == 3) { // 전량 매도
                if (cnt != 0) {
                    money += today * cnt;
                }
                upCnt = 0;
                cnt = 0;
            }

            else if (downCnt == 3) { // 전량 매수
                if (money >= chart[i]) {
                    cnt += money / chart[i]; // 주식 수 계산
                    money = money % chart[i]; // 현재 남은 현금
                }
            }
        }
        return money + cnt * chart[13];
    }
}

/*
 * <문제 단순화>
 * 준현이는 돈이 있으면 무조건 최대한 많이 사고
 * 성민이는 3일 연속 오르면 다음날 떨어질 것이라고 생각하고 가지고 있는 걸 모두 팔고,
 * 3일 연속 내리면 다음날 오를 것이라고 생각하고 살 수 있는 최대한을 사는 것이다.
 */