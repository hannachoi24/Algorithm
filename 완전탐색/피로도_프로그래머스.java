package 완전탐색;

class 피로도_프로그래머스 {
    static boolean[] visit;
    static int answer = 0;

    public int solution(int k, int[][] dungeons) {

        visit = new boolean[dungeons.length];

        dfs(0, k, dungeons);

        return answer;
    }

    public void dfs(int depth, int k, int[][] dungeons) {
        for (int i = 0; i < dungeons.length; i++) {
            if (!visit[i] && dungeons[i][0] <= k) {
                visit[i] = true;
                dfs(depth + 1, k - dungeons[i][1], dungeons);
                visit[i] = false;
            }
        }
        answer = Math.max(answer, depth);
    }
}