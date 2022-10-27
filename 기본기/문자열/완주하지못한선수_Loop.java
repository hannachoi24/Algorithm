package 기본기.문자열;

import java.util.Arrays;

public class 완주하지못한선수_Loop {
    public String solution(String[] participant, String[] completion) {
        // 1. 두 배열을 정렬한다.
        Arrays.sort(participant);
        Arrays.sort(completion);

        // 2. 두 배열이 다를 때까지 찾는다.
        int i = 0;
        for (int i = 0; i < completion.length; i++)
            if (!participant.equals(completion[i]))
                break;

        // 3. 여기까지 왔다는 것은 마지막 주자가 완주하지 못했다는 의미이다.
        return participant[i];

    }

    public static void main(String[] args) {
        String[] part = { "leo", "kiki", "eden" };
        String[] comp = { "eden", "kiki" };
        완주하지못한선수_Loop sol = new 완주하지못한선수_Loop();
        System.out.println(sol.solution(part, comp));
    }
}