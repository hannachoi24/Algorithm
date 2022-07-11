package 완전탐색;

import java.io.*;
import java.util.*;

public class 암호만들기 {
    static int L, C; // L: 암호는 서로 다른 L개의 알파벳 소문자들로 구성, C: 암호로 사용했을 법한 문자의 종류는 C가지
    static char[] list; // 알파벳 넣을 배열
    static char[] code; // 완성된 암호를 넣을 배열

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());

        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        list = new char[C];
        code = new char[L];

        st = new StringTokenizer(br.readLine());

        // list 배열 입력
        for (int i = 0; i < C; i++) {
            list[i] = st.nextToken().charAt(0);
        }

        // 순서대로 정렬
        Arrays.sort(list);

        makeCode(0, 0);
    }

    // 최소 한개의 모음, 최소 2개의 자음이 맞다면 출력
    public static void makeCode(int x, int idx) {
        if (idx == L) {
            if (isValid()) {
                System.out.println(code);
            }
            return;
        }

        // 아직 길이 L의 코드를 만들지 않았고 글자도 아직 남았을 경우
        // 기존에 선택한 알파벳보다 큰 알파벳을 하나씩 선택해나가면서 암호를 만들어 간다.
        for (int i = x; i < C; i++) {
            code[idx] = list[i];
            makeCode(i + 1, idx + 1);
        }
    }

    // 최소 모음 1개, 최소 자음 2개인지 확인
    public static boolean isValid() {
        int mo = 0;
        int ja = 0;

        for (char x : code) {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                mo++;
            } else
                ja++;
        }
        if (mo >= 1 && ja >= 2) {
            return true;
        }
        return false;
    }
}
