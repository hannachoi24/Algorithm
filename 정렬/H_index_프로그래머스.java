package 정렬;

import java.util.*;

public class H_index_프로그래머스 {

    public int solution(int[] citations) {
        int answer = 0;

        // h번 이상 인용된 논문이 h편 이상이고 나머지가 h번 이하인 h의 최댓값을 구하므로
        // 정렬 후 앞에서부터 검사하여 처음 h-index가 성립한 순간을 리턴
        Arrays.sort(citations);

        for (int i = 0; i < citations.length; i++) {
            // h를 줄여가면서 검사
            int h = citations.length - i;
            if (citations[i] >= h) {
                answer = h;
                break;
            }
        }
        return answer;
    }
}
/*
 * 해당 논문보다 인용횟수가 크거나 같은 논문 편수를 h로 잡고, citations[i]값이 h보다 크거나 같아서 조건문에 만족하는 순간의
 * h값을 answer로 반환한다. 조건에 처음으로 만족하는 순간이 H-index 최대값이고 이후로는 무조건 h값이 작아지기 때문에 이후의
 * 차례는 체크할 필요가 없다.
 */
