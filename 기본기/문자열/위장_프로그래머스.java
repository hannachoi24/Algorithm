package 기본기.문자열;

import java.util.HashMap;
import java.util.Iterator;

class Solution {
    public int solution(String[][] clothes) {
        // 1. 옷을 종류별로 구분하기
        HashMap<String, Integer> map = new HashMap<>();

        for (String[] clothe : clothes) {
            String type = clothe[1];
            map.put(type, map.getOrDefault(type, 0) + 1);
        }

        // 2. 입지 않는 경우를 추가하여 모든 조합 계산하기
        Iterator<Integer> it = map.values().iterator();
        int answer = 1;

        while (it.hasNext())
            answer *= it.next().intValue() + 1;
        return answer - 1; // 3. 아무종류의 옷도 입지 않는 경우 제외하기
    }
}

/*
 * 1) HashMap.getOrDefault('B', 0)
 * 
 * 이 함수는 'B'라는 Key에 해당하는 Value가 있으면 가져오고, 아닐 경우 0을 Default로 지정하여 사용하겠다는 의미의
 * 함수이다.
 * Value는 곧 옷 종류의 가짓수가 되기 때문에, 이전에 값이 있었으면 기존 값에 + 1을 하면 되고
 * 없었으면 1을 입력하면 된다.
 * 
 * 2) 모든 옷 종류의 count가 잘 입력되었다면, answer에 곱해주면 된다.
 * 하지만 모든 옷 종류에 대해서 안 입는 경우가 있기 때문에 ans *= it.next().intValue()라고 하지 않고 ans *=
 * it.next().intValue() + 1을 곱해줘야 한다.
 * 즉, +1은 각 옷 종류를 입지 않는 경우를 고려하기 위해 추가되어야 하는 것이다.
 * 
 * 3) 아무리 스파이가 모자 하나만 달랑 입어도 된다고 해도, 아무것도 입지 않는 것은 허용되지 않는 것이 문제의 전제이다.
 * 그렇기 때문에 마지막에 -1을 해줘서 모든 옷의 종류를 입지 않은 경우 1개를 제외시켜준다.
 */
