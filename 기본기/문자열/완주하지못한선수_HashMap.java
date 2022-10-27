package 기본기.문자열;

import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;

public class 완주하지못한선수_HashMap {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        HashMap<String, Integer> map = new HashMap<>();

        for (String player : participant) {
            map.put(player, map.getOrDefault(player, 0) + 1); // 참가자 이름에 해당하는 값을 1로 세팅
        }

        for (String player : completion) {
            map.put(player, map.get(player) - 1); // 완주자들은 위에서 세팅한 값에 -1을 해준다.
        }

        Iterator<Map.Entry<String, Integer>> iter = map.entrySet().iterator();

        while (iter.hasNext()) {
            Map.Entry<String, Integer> entry = iter.next();
            if (entry.getValue() != 0) // 값이 0이 아니면 완주하지 못한 사람
                answer = entry.getKey();
            break;
        }

        return answer;
    }

    public static void main(String[] args) {
        String[] part = { "leo", "kiki", "eden" };
        String[] comp = { "eden", "kiki" };
        완주하지못한선수_HashMap sol = new 완주하지못한선수_HashMap();
        System.out.println(sol.solution(part, comp));
    }
}

/*
 * 1) HashMap 만들기 -> Key는 Participant의 이름, Value는 Count
 * 
 * 2) Count Table을 만들어서 각 Participant의 Count를 세어 놓는다.
 * 다음 단계에서는 완주한 사람들은 Value를 1씩 빼는 동작을 하고, 그러면 남아있는 한 사람이 완주하지 못한 선수가 될 것이다.
 * 
 * HashMap.getOrDefault('B', 0)
 * 이 함수는 'B'라는 Key에 해당하는 Value가 있으면 가져오고, 아닐 경우 0을 Default로 지정하여 사용하겠다는 의미의
 * 함수이다.
 * "Value를 전부 1로 하면 되지 않을까?"라는 의문이 생긴다면, 동명이인이 있는 예외 케이스를 고민해보면 좋다.
 * 즉, HashMap이 Count Table과 동일한 역할을 해야 되기 때문에, 단순히 0/1로 있다 없다를 표현하는 것으로는 부족하고,
 * A라는 이름을 가진 참가자가 몇 명인지를 알아야 하는 것이다.
 * 
 * 3) HashMap에서 완주한 선수 빼기
 * 각 선수들의 이름이 Key로 들어가고, 그 이름을 가진 사람이 몇 명 있는지 Value로 Hash Map을 완성
 * 이 HashMap에서 완주자들을 제외시키면, 한 명만 남게 될 것이고 이것이 찾는 정답
 * 
 * 4) Value가 0이 아닌 참가자 찾기
 * 남아있는 1명이 완주하지 못한 사람이니, 이제 HashMap을 한번 돌면서 Value가 0이 아닌 사람을 찾으면 된다.
 * HashMap.keySet() : HashMap이 들고 있는 전체 Key의 배열을 반환하는 함수
 * HashMap.get(Key) : Key에 해당하는 Value를 반환하는 함수이다.
 * 즉, 전체 Key를 하나씩 확인해서 Value가 0이 아닌 경우 answer에 담아주는 동작을 하는 코드이다.
 */