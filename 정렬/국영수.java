package 정렬;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 국영수 {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        PriorityQueue<student> q = new PriorityQueue<student>();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int kor = Integer.parseInt(st.nextToken());
            int eng = Integer.parseInt(st.nextToken());
            int mat = Integer.parseInt(st.nextToken());
            q.add(new student(kor, eng, mat, name));
        }

        while (!q.isEmpty()) {
            student tmp = q.poll();
            sb.append(tmp.name).append("\n");
        }
        System.out.println(sb);
    }

}

class student implements Comparable<student> {
    int kor, eng, mat;
    String name;

    @Override
    public int compareTo(student o) {
        if (this.kor == o.kor) {
            if (this.eng == o.eng) {
                if (this.mat == o.mat) {
                    return this.name.compareTo(o.name); // 모든 점수가 같으면 이름 사전순으로 출력
                }

                return o.mat - this.mat; // 영어랑 국어점수가 같으면 수학점수가 감소하는 순서로
            }
            return this.eng - o.eng; // 국어점수가 같으면 영어점수가 증가하는 순서로
        }
        return o.kor - this.kor; // 국어점수가 감소하는 순서로
    }

    public student(int kor, int eng, int mat, String name) {
        super();
        this.kor = kor;
        this.eng = eng;
        this.mat = mat;
        this.name = name;
    }
}

/*
 * 우선순위큐로 풀면 되는 문제이다.
 * 자바에서는 우선순위큐를 풀기위해서는 Comparable 이라는 인터페이스를 implements 하면 된다.
 * 메소드에 원하는 정렬을 정의하면 되는데,
 * this.mat : 인덱스가 앞서는 원소, o.mat : 인덱스가 뒤에있는 원소라고 생각하면 된다.
 * 앞에꺼 빼기 뒤에꺼 즉, this.mat - o.mat 이 양수면 둘이 뒤집힌다. 즉 앞에있는 것이 클 때 (ex. 6과 4)
 * 뒤집힌다는 것은 오름차순이라고 생각하면 된다.
 * this.mat - o.mat 이 음수면 가만히 있는다.
 * => 정리 : comparable 사용시, 앞-뒤 계산 후 결과 값이 양수면 오름차순정렬, 음수면 내림차순정렬!
 */