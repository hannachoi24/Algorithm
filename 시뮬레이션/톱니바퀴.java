package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 톱니바퀴 {
    static int[][] state = new int[4][8];
    static int k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int i = 0; i < 4; i++) {
            String line = br.readLine();
            for (int j = 0; j < 8; j++) {
                state[i][j] = line.charAt(j) - '0'; // char형을 Int형으로 변환
            }
        }

        k = Integer.parseInt(br.readLine());

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken()) - 1;
            int dir = Integer.parseInt(st.nextToken());
            gearOperation(idx, dir); // 톱니바퀴를 회전시키려면, 회전시킬 톱니바퀴(idx)와 회전시킬 방향(dir)을 결정
        }

        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += Math.pow(2, i) * state[i][0]; // 12시방향에 있는 N,S극 정보를 받아 총점수 계산
        }
        System.out.println(total);
    }

    static void gearOperation(int idx, int dir) {
        // 왼쪽 (0 ~ idx -1)
        leftSide(idx - 1, -dir);
        // 오른쪽 (idx + 1 ~ 3)
        rightSide(idx + 1, -dir);
        rotation(idx, dir);
    }

    static void leftSide(int idx, int dir) {
        if (idx < 0)
            return;
        if (state[idx][2] == state[idx + 1][6]) // 맞닿아 있는 극이 같으면 pass
            return;
        leftSide(idx - 1, -dir); // 왼쪽으로 맞물려 있는 톱니바퀴를 재귀를 사용해 회전 시켜준다.
        rotation(idx, dir);
    }

    static void rightSide(int idx, int dir) {
        if (idx > 3)
            return;
        if (state[idx][6] == state[idx - 1][2])
            return;
        rightSide(idx + 1, -dir); // 오른쪽으로 맞물려 있는 톱니바퀴를 재귀를 사용해 회전 시켜준다.
        rotation(idx, dir);
    }

    // 톱니바퀴 회전시키기 -> 시계 방향과 반시계 방향으로 움직인다. 원형의 형태로 이루어져있으므로 끝과 첫부분을 연결지어야 한다.
    static void rotation(int idx, int dir) {
        if (dir == 1) { // 시계방향
            int tmp = state[idx][7]; // 12시 방향에
            for (int i = 7; i > 0; i--) {
                state[idx][i] = state[idx][i - 1];
            }
            state[idx][0] = tmp;
        } else {
            int tmp = state[idx][0];
            for (int i = 0; i < 7; i++) {
                state[idx][i] = state[idx][i + 1];
            }
            state[idx][7] = tmp;
        }
    }
}

/*
 * 구현 문제로 각 로직을 독립적으로 설계한 다음 동작시켜 풀이하였다. 선택된 idx 톱니바퀴 기준으로 왼쪽과 오른쪽으로 마주하는 자석이
 * 상극일 경우 회전이 맞물려서 돌아간다. 이에대한 동작과정을 재귀를 통해 구현하였다.
 * 
 * <톱니바퀴 회전시키기>
 * 시계 방향과 반시계 방향으로 움직인다. 원형의 형태로 이루어져있으므로 끝과 첫부분을 연결지어야 한다.
 * 
 * <회전 연계시키기>
 * 모든 톱니바퀴는 붙어있으므로 회전이 연속적으로 이루어져야 한다. 이를 재귀호출로 구현해주면 된다.
 * 현재의 톱니바퀴를 기준으로 오른쪽 톱니바퀴와 왼쪽 톱니바퀴가 각 상극으로 이루어져 있을 경우 현재 방향과 반대 방향으로 동작시켜준다.
 * 
 * <설계>
 * 1. 톱니바퀴에 대한 정보를 이차원 배열에 저장한다. state[i][j] = line.charAt(j)-'0';
 * 2. (idx, dir) 회전할 톱니바퀴와 방향에 대한 정보를 입력받으면 톱니바퀴 연산을 동작시킨다.
 * -> gearOperation(idx,dir);
 * 2-1. 왼쪽으로 맞물려있는 톱니바퀴를 재귀를 사용하여 회전시켜준다. leftSide(idx-1, -dir);
 * 2-2. 오른쪽 또한 마찬가지로 재귀를 사용하여 회전시켜준다. rightSide(idx+1, -dir);
 * 3. 모든 회전이 끝났으면 12시방향에 있는 N,S극 정보를 받아 점수를 출력해준다.
 */