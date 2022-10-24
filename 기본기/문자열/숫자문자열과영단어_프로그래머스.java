package 기본기.문자열;

class 숫자문자열과영단어_프로그래머스 {
    public int solution(String s) {
        String num[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
        String word[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

        for (int i = 0; i < 10; i++) {
            s = s.replaceAll(word[i], num[i]);
        }

        return Integer.parseInt(s);
    }
}
