import java.util.Arrays;

class Solution
{
public
    String[] solution(String[] files)
    {
        Arrays.sort(
            files, (o1, o2)->{
                String head1 = o1.split("[0-9]")[0].toLowerCase();
                String head2 = o2.split("[0-9]")[0].toLowerCase();
                if (head1.compareTo(head2) == 0)
                {                                                   // head가 같은 문자열일 경우 number로 정렬
                    String numTail1 = o1.substring(head1.length()); // head가 끝나는 부분 부터 이후의 값 가져옴
                    String numTail2 = o2.substring(head2.length());
                    return Integer.parseInt(calNumber(numTail1)) - Integer.parseInt(calNumber(numTail2));
                }
                else
                {
                    return head1.compareTo(head2);
                }
            });
        return files;
    }

private
    static String calNumber(String numTail2)
    { // 최대 5자리인 number 계산
        StringBuilder sb = new StringBuilder();
        for (char c : numTail2.toCharArray())
        {
            if (Character.isDigit(c) && sb.length() <= 5)
            {
                sb.append(c);
            }
            else
            {
                return sb.toString();
            }
        }
        return sb.toString();
    }

public
    static void main(String[] args)
    {
        Solution solution = new Solution();
        solution.solution(new String[]{"img12.png", "img10.png", "img02.png", "img1.png", "IMG01000000.GIF", "img2.JPG"});
    }
}
