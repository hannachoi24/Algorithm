package 완전탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 사탕게임 {
    static int n; // 맵 크기
    static char[][] arr; // board
    static int max = 0; // 먹을 수 있는 최대 사탕개수

    // 가로로, 세로로 비교하면서 먹을 수 있는 사탕의 최대 갯수 찾기
    public static void check(char[][] arr) {
        // → 가로로 체크
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 0; j < n - 1; j++) {
                // 이전 사탕과 동일한 경우 계속 먹음
                if (arr[i][j] == arr[i][j + 1]) {
                    count++;
                    // 이전과 다른 사탕인 경우 새로 먹어야하므로 1로 초기화
                } else {
                    count = 1;
                }
                max = Math.max(max, count);
            }
        }
        // ↓세로로 체크
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 0; j < n - 1; j++) {
                if (arr[j][i] == arr[j + 1][i]) {
                    count++;
                } else {
                    count = 1;
                }
                max = Math.max(max, count);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        arr = new char[n][n];

        // NxN 사탕 입력 받기
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = line.charAt(j);
            }
        }

        // 가로로 인접한 두 사탕 교환하고 최대 사탕 개수 찾고 원위치
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                // 가로로 인접한 두 문자 교환
                char temp = arr[i][j];
                arr[i][j] = arr[i][j + 1];
                arr[i][j + 1] = temp;

                check(arr);

                // 이전에 교환한 문자 복구
                temp = arr[i][j];
                arr[i][j] = arr[i][j + 1];
                arr[i][j + 1] = temp;
            }
        }

        // 세로로 인접한 두 사탕 교환하고 최대 사탕 개수 찾고 원위치
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                char temp = arr[j][i];
                arr[j][i] = arr[j + 1][i];
                arr[j + 1][i] = temp;

                check(arr);

                temp = arr[j][i];
                arr[j][i] = arr[j + 1][i];
                arr[j + 1][i] = temp;
            }
        }
        System.out.println(max);
    }
}

/*
 * 오른쪽, 아래를 확인해서 현재 값과 같다면 +1을, 그렇지 않으면 다시 1로 초기화를 했다.
 * swap을 했을 때 check를 하고, 이후 원래대로 고쳐야 하기에 다시 한번 swap을 구현했다.
 * 문제를 풀 때 주의할 점은, swap 메소드에 대한 이해, 오른쪽과 아래를 확인하면서 개수를 늘려가는 부분, 이 2가지라고 생각한다.
 */