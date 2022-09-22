package 그리디;

import java.io.*;
import java.util.StringTokenizer;

/*
 * 1. 2칸 위로, 1칸 오른쪽
 * 2. 1칸 위로, 2칸 오른쪽
 * 3. 1칸 아래로, 2칸 오른쪽
 * 4. 2칸 아래로, 1칸 오른쪽
 *
 * 이동 횟수가 네번을 넘으면 모든 이동방법을 한 번씩 사용해야 한다.
 * 네번을 넘지 못하면 이동 방법에 제약이 없다. 즉, 이동 방법에 제약이 없는 경우
 * 최대 이동 칸수는 네 칸이다. (중요)
 *
 * 세로가 1 or 2 or 3이상
 * 세로가 1 → 한 칸밖에 없으므로 1
 * 세로가 2 → 조건 1, 조건 4를 사용하지 못하므로 이동 제약이 없는 경우 최대 이동 칸수는 네칸이다. 
 * 세로가 3 → 가로가 6이하인 경우 최대 이동 칸은 모든 조건을 다 써도 4칸이다.
 */

public class 병든나이트 {
    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        System.out.println(solve());
    }

    static int solve() {
        if (N == 1)
            return 1;
        if (N == 2)
            return Math.min(4, (M + 1) / 2);
        if (M < 7)
            return Math.min(4, M);
        return M - 2;
    }
}
