package 완전탐색;

import java.util.*;

class 모든순열 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.close();
        int[] arr = new int[n];
        int[] output = new int[n];
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        perm(arr, output, visited, 0, n, n);
    }

    // 순서를 지키면서 n개 중에서 r개를 뽑는 경우
    static void perm(int[] arr, int[] output, boolean[] visited, int depth, int n, int r) {
        if (depth == r) {
            print(output, r);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] != true) {
                visited[i] = true; // 방문처리
                output[depth] = arr[i]; // 해당 순열 넣어줌
                perm(arr, output, visited, depth + 1, n, r); // 다음으로 넘어감
                visited[i] = false;

            }
        }
    }

    static void print(int[] arr, int r) {
        for (int i = 0; i < r; i++)
            System.out.print(arr[i] + " ");
        System.out.println();

    }
}

/*
 * N이 주어졌을 때 구할 수 있는 모든 순열을 사전순으로 출력 -> DFS 이용, n개중에서 r개를 뽑는 순열-> 문제는 n개 중 n개를
 * 뽑는 경우밖에 없으므로 nPn
 * 
 * 1. 선언할 변수들
 * -> 순열을 만들 배열 arr
 * -> 순열을 만든 후 배열 output
 * -> 방문여부를 기록할 visited 배열
 * -> n 선언
 * 
 * 2. 첫자리에 올 수를 반복문을 통해 하나씩 넣는다. 사전순이으로 출력해야하니까 1부터 쭉 넣어준다.
 * 
 * 3. 배열에 넣은 수는 visited[] 배열을 통해 방문 했음을 표시한다. 그리고 방문한 곳을 제외하고 다시 반복문을 돌린다.
 * 
 * 4. 모든곳을 방문하면 현재 값을 출력해주고 return으로 종료해준다.
 * 
 * depth는 현재가 몇번째 반복문을 돌고있는지를 표시해주고, start는 이번에 넣을 데이터이다.
 * base case로 depth가 n과 같아지면 종료를 해준다.
 */