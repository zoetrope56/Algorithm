package test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;


public class Test201217_1 {

	public static String solution(int[] numbers) {
		String answer = "";	
		ArrayList<String> arr = new ArrayList();
		//Arrays.sort(numbers);
		
		for(int n:numbers) {
			arr.add(String.valueOf(n));
		}
		
		Collections.sort(arr, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return (o2+o1).compareTo(o1+o2);
			}
		});
		
		if(arr.get(0).equals("0"))
			return "0";
		
		for(String str:arr)
			answer+=str;
		
		return answer;
	}

	public static void main(String args[])	{

		int[] arr1 = {6, 10, 2};
		int[] arr2 = {3, 30, 34, 5, 9};
		int[] arr3 = {40,400};
		int[] arr4 = {40,404};
		int[] arr5 = {12,121};
		int[] arr6 = {3054,305};
		int[] arr7 = {40,405};
		int[] arr8 = {2,22,223};
		int[] arr9 = {0,0,0,0};	// 0
		
		System.out.println(solution(arr1));
		System.out.println(solution(arr2));
		System.out.println(solution(arr3));
		System.out.println(solution(arr4));
		System.out.println(solution(arr5));
		System.out.println(solution(arr6));
		System.out.println(solution(arr7));
		System.out.println(solution(arr8));
		System.out.println(solution(arr9));

	}

	/**
	 * 문제 설명
	 * 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
	 * 예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 
	 * 이중 가장 큰 수는 6210입니다.
	 * 
	 * 0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 
	 * 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.
	 * 
	 * 제한 사항
	 * numbers의 길이는 1 이상 100,000 이하입니다.
	 * numbers의 원소는 0 이상 1,000 이하입니다.
	 * 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
	 * 
	 * 입출력 예
	 * numbers	return
	 * [6, 10, 2]	6210
	 * [3, 30, 34, 5, 9]	9534330
	 * 
	 */

}
