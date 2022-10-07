package 그래프;

import java.io.*;
import java.util.*;

public class 퍼즐 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        Queue<String> q = new LinkedList<>(); // BFS 돌리기 위함
        HashMap<String, Integer> map = new HashMap<>(); // 중복 체크

        for (int i = 0; i < 3; i++) {
            sb.append(br.readLine().replace(" ", ""));
        }

        if (sb.toString().equals("123456780")) // 이미 완성된 퍼즐
            System.out.println("0");
        else {
            map.put(sb.toString(), 0);
            q.offer(sb.toString());
            System.out.println(bfs(q, map));
        }
    }

    public static int bfs(Queue<String> q, HashMap<String, Integer> map) {
        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        while (!q.isEmpty()) {
            String str = q.poll();
            int zeroIdx = str.indexOf("0"); // 0 위치 찾기
            int row = zeroIdx / 3; // map에서 행 위치
            int col = zeroIdx % 3; // 열 위치

            for (int i = 0; i < 4; i++) { // 이동 가능한 범위 체크
                int nx = row + dx[i];
                int ny = col + dy[i];

                if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                    continue;
                int swapIdx = 3 * nx + ny; // 2차원 인덱스를 1차원으로 변환

                // 0과 바꿀 자리를 swap
                StringBuilder sb = new StringBuilder(str);
                char ch = sb.charAt(swapIdx);
                sb.setCharAt(swapIdx, '0');
                sb.setCharAt(zeroIdx, ch);

                // 정답 찾음
                if (sb.toString().equals("1234567890"))
                    return map.get(str) + 1;

                // 새로 만들어진 문자열인 경우
                if (!map.containsKey(sb.toString())) {
                    q.offer(sb.toString()); // 큐에 넣어 나중에 다시 체크
                    map.put(sb.toString(), map.get(str) + 1);
                }
            }
        }

        return -1;
    }
}
