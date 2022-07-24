package 시뮬레이션;

import java.util.*;

public class 게리맨더링_CleanCode {

    static int n; // 구역 수
    static int[] population, area; // population: 인구 수, area: 지역별 선거구를 저장해줄 배열
    static ArrayList<Integer>[] list;
    static int min = Integer.MAX_VALUE;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();

        population = new int[n + 1];
        list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<>();
            population[i] = scan.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            int num = scan.nextInt();
            for (int j = 0; j < num; j++) {
                list[i].add(scan.nextInt());
            }
        }

        area = new int[n + 1]; // 각 지역구가 속한 선거구 저장. 1 또는 2
        dfs(1); // 뽑을 수 있는 모든 지역구를 뽑는 dfs탐색

        if (min == Integer.MAX_VALUE)
            System.out.println("-1");
        else
            System.out.println(min);
    }

    public static void dfs(int k) {
        if (k == n + 1) { // 모든 지역 다 뽑았다면
            int area1 = 0;
            int area2 = 0;
            for (int i = 1; i <= n; i++) {
                if (area[i] == 1)
                    area1 += population[i];
                else
                    area2 += population[i];
            }

            visited = new boolean[n + 1];
            int link = 0; // 연결된 지역들의 개수를 셈.
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    bfs(i, area[i]); // 연결된 지역들을 모두 방문표시하는 bfs탐색
                    link++;
                }
            }
            // 지역이 2개뤄 나눠졌고, 2지역안에서 서로 연결되어 있다면 최소값 계산
            if (link == 2)
                min = Math.min(min, Math.abs(area1 - area2));

            return;
        }

        area[k] = 1; // k지역 1번 선거구에 할당.
        dfs(k + 1);

        area[k] = 2; // k지역 2번 선거구에 할당.
        dfs(k + 1);
    }

    public static void bfs(int idx, int areaNum) {
        Queue<Integer> q = new LinkedList<>();
        visited[idx] = true;
        q.offer(idx);

        while (!q.isEmpty()) {
            int current = q.poll();

            for (int i = 0; i < list[current].size(); i++) {
                int next = list[current].get(i);
                if (area[next] == areaNum && !visited[next]) {
                    q.offer(next);
                    visited[next] = true;
                }
            }
        }
    }
}

/*
 * 구현능력 + 완전탐색 + DFS/BFS 개념을 모두 활용해 볼 수 있는 문제이다.
 * 
 * 우선, 문제의 조건을 구현 순서에 맞게 정리해보자.
 * 
 * 지역에 두 개의 선거구 중에 하나를 할당한다. (1 또는 2로 표현)
 * 나눠진 지역들이 두개의 구역으로 연결되는지 확인한다. (DFS/BFS 탐색으로 구함)
 * 두 지역의 차이 값 중에서 최소값을 찾아준다.
 * 
 * 1. 지역에 두 개의 선거구 중에 하나를 할당한다.
 * 
 * 지역별 선거구를 저장해줄 배열을 area로 만들어주었다.
 * 
 * 할당할 때에는 조합으로 할 수도 있고, 완전 탐색으로도 할 수 있다.
 * 
 * 나는 DFS방식의 완전탐색을 해주었다.
 * 
 * 1번 지역구 부터 시작하여 선거구를 할당하기 시작했고, 1번 선거구를 우선 할당한 다음, 조건에 부합하지 않아 return되었다면 2번
 * 선거구를 할당하도록 하였다.
 * 
 * 이때 두 지역간 인구 수의 차를 구해야 하므로 area1, area2 변수를 생성하여 지역별 인구수를 저장하도록 하였다.
 * 
 * 
 * 
 * 2. 나눠진 지역들이 두 개의 구역으로 연결되는지 확인한다.
 * 
 * 이 부분은 DFS, BFS 둘중 어떤 알고리즘을 사용해도 무방하다.
 * 
 * 탐색 중에 신경써줘야 할 부분은 선거구가 동일해야하고, 이전에 방문하지 않은 지역인지 확인하며 탐색하는 부분이다.
 * 
 * 탐색 후에 link개수를 더해주어 구역이 나눠지는 개수를 세어 주도록 하였다.
 * 
 * 연결된 지역의 개수를 세고 난 다음 link가 2라면 두개의 지역으로 연결되어 나누어진 것이므로 다음 연산을 수행해 준다.
 * 
 * 
 * 
 * 3. 두 지역의 차이 값 중에 최소값을 찾아준다.
 * 
 * 1번에서 두 지역간 인구 수의 차이를 area1, area2로 구해주었으므로 현재의 최소값과 두 지역차의 절대값(Math.abs(area1
 * - are2))중에서 더 작은 값을 최소값으로 계산해 주면 된다.
 */