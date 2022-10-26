package 기본기.문자열;

import java.util.Arrays;

class 전화번호목록_startsWith {
    public boolean solution(String[] phone_book) {
        boolean answer = true;

        // 1. phoneBook을 sorting한다.
        Arrays.sort(phone_book);

        // 2. 1중 Loop을 돌며 앞 번호가 뒷 번호의 접두어인지 확인한다.
        for (int i = 0; i < phone_book.length - 1; i++) {
            if (phone_book[i + 1].startsWith(phone_book[i])) {
                return false;
            }
        }

        // 3. 여기까지 오면 접두어가 없다는 것이다.
        return answer;
    }
}
