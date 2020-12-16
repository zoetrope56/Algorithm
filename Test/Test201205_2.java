package test;

import java.util.ArrayList;

public class Test201205_2 {
	public static String solution(String phone_number) {
		String answer = "";
		ArrayList<Character> arr = new ArrayList<>();

		for(int i = 0; i < phone_number.length(); i++) {
			arr.add(phone_number.charAt(i));
		}

		for (int i = 0; i < phone_number.length()-4; i++) {
			arr.set(i, '*');
		}
		
		for (int j = 0; j < phone_number.length(); j++) {
			answer += arr.get(j);
		}

		return answer;

	}
	public static void main(String args[]) {
		
		System.out.println(solution("01041391258"));

	}

	/*
	 * 프로그래머스 모바일은 개인정보 보호를 위해 고지서를 보낼 때 고객들의 전화번호의 일부를 가립니다.
	 * 전화번호가 문자열 phone_number로 주어졌을 때, 
	 * 전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열을 리턴하는 함수, 
	 * solution을 완성해주세요.
	 * 
	 * 01033334444 -> *******4444
	 * 027778888 ->	*****8888
	 * 
	 */
}
