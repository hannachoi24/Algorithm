package 그리디;

import java.util.Arrays;
import java.util.Scanner;

public class 단어수학 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n]; // 문자열
        int[] alpha = new int[26]; // 더해서 나온 값 저장할 배열

        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();
        }

        for (int i = 0; i < n; i++) {
            int temp = (int) Math.pow(10, arr[i].length() - 1);
            for (int j = 0; j < arr[i].length(); j++) {
                alpha[(int) arr[i].charAt(j) - 65] += temp; // char타입의 변수에 'A' 또는 'A'에 해당하는 아스키 코드 65를 빼면 int 값이 리턴
                temp /= 10;
            }
        }

        Arrays.sort(alpha);
        int index = 9;
        int sum = 0;
        for (int i = alpha.length - 1; i >= 0; i--) {
            if (alpha[i] == 0) {
                break;
            }
            sum += alpha[i] * index;
            index--;
        }
        System.out.println(sum);
    }
}

/*
 * 이 문제의 정답은 'max'값을 찾는것이다. 따라서 높은 자릿수에 높은 값(9~0) 을 부여하면 된다.
 * 
 * GCF는 총 3자리이다. 따라서 100부터 시작한다.
 * 
 * 100G, 10C, 1F
 * 
 * 
 * ACDEB는 총 5자리이다. 따라서 10000부터 시작한다.
 * 
 * 10000A, 1000C, 100D, 10E, 1B
 * 
 * 
 * GCF의 값과 ACDEB의 값을 더해보자.
 * 
 * 10000A, 1B, 1010C, 100D, 10E, 1F, 100G 이 나오게 된다.
 * 
 * 
 * 나온 값을 26개의 int형 배열을 생성하여 넣어준후, 정렬한다. (26개를 생성한 이유는 A-Z가 총 26개이기 때문이다.)
 * 
 * 
 * 높은값부터 9~0씩 곱하면 답을 구해낼 수 있다.
 */