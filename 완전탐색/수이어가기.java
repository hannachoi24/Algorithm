package 완전탐색;

import java.util.*;
import java.io.*;

public class 수이어가기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        List<Integer> list = new ArrayList<>();
        List<Integer> copy = new ArrayList<>();

        int max = 0;

        for (int i = n; i >= 1; i--) { // n 부터 1까지 두번째 수 까지 선택하기
            list.add(n); // list 첫번째
            list.add(i); // list 두번째

            // list 세번째 부터
            while (true) {
                // i-1 - i-2를 구해서 음수인지 체크
                int num = list.get(list.size() - 2) - list.get(list.size() - 1);
                if (num < 0)
                    break;
                else
                    list.add(num);
            }

            if (max < list.size()) { // 최대 크기 업데이트
                max = list.size();
                copy.clear(); // 갱신 되기 전 까지의 copy 했던 것들 지우기
                copy.addAll(list); // 최대 크기이면 배열 복사
            }
            list.clear(); // 매번 초기화 해주기
        }

        StringBuilder sb = new StringBuilder();
        sb.append(max + "\n");

        for (int i = 0; i < copy.size(); i++) {
            sb.append(copy.get(i) + " ");
        }

        System.out.print(sb);

    }
}

/*
 * 첫 번째 수를 입력으로 받고 두번째 수를 선택한 뒤 세번째 부터는 앞에 두 개의 숫자를 빼면서 하나씩 새로운 수를 만들어가는 문제이다. 
 * 1. N 부터 1 까지 하나씩 두번째 수 까지 선택 한다.
 * 2. 세번째 수 부터는 음수 값이 나올 때 까지 while문에서 하나씩 만들면서 list에 추가한다.
 * 3. 하나의 list가 만들어질 때마다 최대 크기를 비교해서 업데이트하고, 업데이트가 되는 경우엔 배열도 같이 복사해준다.
 * 4. 마지막엔 최종적으로 max에 담겨있는 개수와 list를 출력해줬다.
 */
