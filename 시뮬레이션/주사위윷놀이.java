package 시뮬레이션;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 주사위윷놀이 {
    private static class Node {
        int score, red, blue; // score: 해당 칸의 점수, red: 빨간 화살표로 이동할 경우의 다음 점, blue: 파란 화살표로 이동할 경우의 다음 점
        boolean isBlue = false; // 파란점인지 여부

        Node(int score, int red) {
            this.score = score;
            this.red = red;
        }
    }

    private static int max = 0, permu[], step[], now[];
    private static boolean[] existCheck;
    private static Node[] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        map = new Node[43];
        permu = new int[10];

        step = new int[10];
        for (int i = 0; i < 10; i++) {
            step[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i <= 40; i += 2) {
            map[i] = new Node(i, i + 2);
        }

        /*
         * 문제에서는 칸의 번호와 점수가 동일한데, 같은 번호가 있는 칸이 두개씩 있는 경우가 있어
         * 겹치는 번호들에 한해서 번호를 바꿔서 지정
         */
        map[10].isBlue = map[20].isBlue = map[30].isBlue = true;
        map[10].blue = 11;
        map[20].blue = 17;
        map[30].blue = 31;

        map[11] = new Node(13, 13); // (주어진 해당 score, 연결노드)
        map[13] = new Node(16, 15);
        map[15] = new Node(19, 25);
        map[17] = new Node(22, 19);
        map[19] = new Node(24, 25);
        map[25] = new Node(25, 37);
        map[31] = new Node(28, 33);
        map[33] = new Node(27, 35);
        map[35] = new Node(26, 25);
        map[37] = new Node(30, 39);
        map[39] = new Node(35, 40);
        map[42] = new Node(0, 42);

        permu[0] = 0;
        permu(9, 0);
        System.out.println(max);
    }

    private static void permu(int n, int k) {
        if (n == k) {
            now = new int[4];
            existCheck = new boolean[43]; // 말이 해당 칸에 있는지 없는지
            move();
            return;
        }

        for (int i = 0; i < 4; i++) {
            permu[k] = i;
            permu(n, k + 1);
        }
    }

    private static void move() {
        int score = 0;

        for (int i = 0; i < 10; i++) {
            int end = horseMove(permu[i], step[i]);
            if (end == -1)
                return;
            now[permu[i]] = end;
            score += map[end].score;
        }
        if (max < score)
            max = score;
    }

    private static int horseMove(int horse, int step) {
        int temp = now[horse];

        for (int i = 0; i < step; i++) {
            if (i == 0 && map[temp].isBlue) {
                temp = map[temp].blue;
                continue;
            }
            temp = map[temp].red;
        }

        if (temp <= 40 && existCheck[temp]) {
            return -1;
        } else {
            existCheck[now[horse]] = false;
            existCheck[temp] = true;
            return temp;
        }
    }
}

/*
 * 파란점일 때/ 아닐 때를 구분해서 리스트를 구현해주면 생각보다 쉽게 풀 수 있다.
 * 문제에서는 칸의 번호와 점수가 동일한데, 같은 번호가 있는 칸이 두개씩 있는 경우가 있어
 * 겹치는 번호들에 한해서 번호를 바꿔서 지정
 * + 도착점을 처리하기 위해서, 도착점인 42번 점은 다음 점도 42가 되게 해서 범위를 초과하지 않게끔 설정
 * + 생성자를 쓰면 매번 새롭게 생성되므로, 다른 v 값을 추가하고 싶을 때에는 .으로 접근해서 설정할 것!
 */