package 그리디;

import java.util.*;

/*
서로 겹치지 않는 회의에 대해 종료시간이 빠르면 더 많은 회의를 선택할 수 있음
시작 시간을 기준으로 오름 차순 정렬을 하고 시작 시간이 같을 경우를 대비해 다시 종료 시간 기준으로 오름 차순 정렬
작은 시간부터 체크를 해서 연속으로 이어갈 수 있도록 해주면 된다.
*/

public class 회의실배정 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int arr[][] = new int[N][2];

        // [i][0]: 시작 시간, [i][1]: 종료 시간
        for (int i = 0; i < N; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }

        // 0번 인덱스 (시작 시간) 기준으로 오름 차순 정렬
        Arrays.sort(arr, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        // 시작 시점이 같을 경우를 대비해서 다시 1번 인덱스 (종료 시간) 기준으로 오름 차순 정렬
        Arrays.sort(arr, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });

        int count = 0;
        int end_time = 0;

        // 시작 시간이 end_time 보다 크거나 같으면 end_time을 그 행의 끝나는 시간으로 두고 count증가
        // 종료시간이 빠르면 된다.
        for (int i = 0; i < N; i++) {
            if (arr[i][0] >= end_time) {
                end_time = arr[i][1];
                count++;
            }
        }

        System.out.println(count);

    }
}
