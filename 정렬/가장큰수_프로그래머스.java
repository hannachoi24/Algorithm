package 정렬;

import java.util.*;

class 가장큰수_프로그래머스 {
    public String solution(int[] numbers) {
        String answer = "";

        // 1. 입력 데이터를 문자열 배열로 변환
        String[] str = new String[numbers.length];

        // int배열 String 배열로 변환
        for (int i = 0; i < str.length; i++) {
            str[i] = String.valueOf(numbers[i]);
        }

        // 2. Comparator 인터페이스로 정렬 기준을 설정(내림차순 정렬)
        Arrays.sort(str, new Comparator<String>() {
            public int compare(String a, String b) {
                return (b + a).compareTo(a + b);
                // 오름차순 정렬 (o1+o2).compareTo(o1+o2);
            }
        });

        // 3. 모든 문자열 연결
        for (String s : str)
            answer += s;

        // 4. 입력 데이터가 모두 0인 경우 예외 처리 -> 0값이 중복일경우 ex){0,0,0}
        // 답이 000이 나오면 안되므로 첫번째값이 0이면 0을 리턴
        if (str[0].equals("0"))
            answer = "0";

        return answer;
    }
}

/*
 * 문자열로 변환 후 내림차순으로 정렬하는 방법인데
 * 일반적으로 내림차순 정렬을 시켰을때 2번째 예에서 3과 30이 "330"이 아닌 "303"이 되어버린다.
 * 따라서 Comparator를 사용하여 문자열을 붙여서 판단 후 내림차순 정렬해야한다.
 * a.compareTo(b)
 * - 앞에서부터 비교하다 다른 문자열이 나오면 'a-b' 순서로 해당 문자의 아스키코드 값을 뺀 결과(int)를 리턴 
 * 내림차순 : (o2+o1).compareTo(o1+o2)
 * 오름차순 : (o1+o2).compareTo(o1+o2)
 */
