package 기본기.문자열;

import java.util.*;

public class 베스트앨범_프로그래머스 {
    static class Music {
        String genre;
        int play;
        int idx;

        public Music(String genre, int play, int idx) {
            this.genre = genre;
            this.play = play;
            this.idx = idx;
        }
    }

    public static int[] solution(String[] genres, int[] plays) {

        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            map.put(genres[i], map.getOrDefault(genres[i], 0) + plays[i]);
        }

        // 1. 장르 선정
        ArrayList<String> genres_ordered = new ArrayList<>();
        while (map.size() != 0) {
            int max = -1;
            String max_key = "";
            for (String key : map.keySet()) {
                int tmp_cnt = map.get(key);
                if (tmp_cnt > max) {
                    max = tmp_cnt;
                    max_key = key;
                }
            }
            genres_ordered.add(max_key);
            map.remove(max_key);
        }

        // 2. 장르 내 노래 선정
        ArrayList<Music> result = new ArrayList<>();
        for (String gern : genres_ordered) {
            ArrayList<Music> list = new ArrayList<>();
            for (int i = 0; i < genres.length; i++) {
                if (genres[i].equals(gern)) {
                    list.add(new Music(gern, plays[i], i));
                }
            }
            Collections.sort(list, (o1, o2) -> o2.play - o1.play); // 내림차순 정렬
            result.add(list.get(0)); // 1개는 무조건 수록
            if (list.size() != 1) { // 더 수록할 곡이 있으면(장르 내의 노래가 1개보다 많으면)
                result.add(list.get(1));
            }
        }

        // 결과 출력
        int[] answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i).idx;
        }
        return answer;
    }
}

/*
 * 다음과 같은 조건을 만족해서 베스트 앨범을 만들어야한다.
 * 
 * 1. 속한 노래가 많이 재생된 장르를 먼저 수록
 * 2. 장르 내에서 많이 재생된 노래를 먼저 수록
 * 3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록
 * 이 조건을 만족하기 위해서는,
 * 
 * 첫번째, 각각 장르별 속한 노래의 전체 재생 횟수를 카운트해서, 전체 재생 횟수로 장르를 내림차순 소팅한다.
 * 두번째, 소팅한 장르 내 노래의 재생 횟수를 각각 카운트해서, 재생 횟수로 노래를 내림차순 소팅한다.
 * 
 * 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록하라는 조건이 있는데, 이는 ArrayList에 Music
 * 정보를 add할 때 idx가 낮은 순서로 넣어주기 때문에 소팅 시 딱히 처리하지 않아도 고유번호가 낮은 순서로 출력이 된다.
 * 
 * count를 하기 위해서는 Hash를 사용하고, 목록을 나타내기 위해서는 List를 사용
 */