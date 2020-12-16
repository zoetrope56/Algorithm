package test;

public class Test201205_1 {
	public static boolean solution(String s) {
		boolean answer = true;
		char[] tmp = s.toCharArray();

		// 문자열 길이 검사
		if(tmp.length == 4 || tmp.length == 6) {
			// 숫자 구성 검사
			for(char n:tmp) {
				if((int)n >= 48 && (int)n <= 57)
					continue;
				else	{
					answer = false;
					break;
				}
			}
		}

		return answer;
	}
	public static void main(String args[])	{
		System.out.println(solution("a234"));

	}

	/*
	 * 문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 
	 * 예를 들어 s가 a234이면 False를 리턴하고 1234라면 True를 리턴하면 됩니다.
	 * 
	 */

}
