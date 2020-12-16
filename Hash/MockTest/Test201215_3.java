package test;

import java.util.HashMap;

public class Test201215_3 {

	public static String solution(String[] participant, String[] completion) {
		String answer = "";
		HashMap<String, Integer> map = new HashMap<>();

		for(String p : participant)
			map.put(p, map.getOrDefault(p, 0)+1);

		for (String comp : completion)
			map.put(comp, map.get(comp)-1);	// 같은 문자열을 찾아 value의 값을 -1해줌
		
		for (String k : map.keySet()) {
			if (map.get(k) != 0) {
				answer = k;
			}
		}

		return answer;
	}

	public static void main(String args[])	{
		String[] p = {"mislav", "stanko", "mislav", "ana"};
		String[] c = {"stanko", "ana", "mislav"};

		String[] p1 = {"leo", "kiki", "eden"};
		String[] c1 = {"kiki", "eden"};

		System.out.println(solution(p, c));
		System.out.println(solution(p1, c1));

	}

	/**
	 * 수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
	 * 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때,
	 * 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.
	 * 
	 */

}