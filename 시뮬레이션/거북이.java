package 시뮬레이션;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 거북이 {

    // 북동남서
    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            int minX = 0, minY = 0, maxX = 0, maxY = 0, dir = 0, nowX = 0, nowY = 0; // dir이 0이면 북쪽을 가리킴

            String command = br.readLine();

            for (int j = 0; j < command.length(); j++) {
                char ch = command.charAt(j);

                if (ch == 'F') {
                    nowX = nowX + dx[dir];
                    nowY = nowY + dy[dir];
                } else if (ch == 'B') {
                    nowX = nowX - dx[dir];
                    nowY = nowY - dy[dir];
                } else if (ch == 'L') {
                    if (dir == 0) // 만약 dir값이 0이면, 현재 북쪽을 가리키고 있는 것 왼쪽으로 90도 회전하면 서쪽을 가리키게 된다.
                        dir = 3; // 따라서 dir값을 3으로 설정하여 서쪽을 나타낸다.
                    else // dir값이 0이 아니라면, 현재 방향에서 왼쪽 90도로 회전하면 이전 방향을 가리키게 된다. dir을 1씩 감소
                        dir--;
                } else if (ch == 'R') {
                    if (dir == 3)
                        dir = 0;
                    else
                        dir++;
                }

                minX = Math.min(minX, nowX);
                minY = Math.min(minY, nowY);
                maxX = Math.max(maxX, nowX);
                maxY = Math.max(maxY, nowY);
            }
            sb.append((Math.abs(minX) + Math.abs(maxX)) * (Math.abs(minY) + Math.abs(maxY)) + "\n"); // 넓이 계산
        }
        System.out.println(sb.toString());
    }
}
