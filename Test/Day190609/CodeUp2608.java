import java.util.Arrays;
import java.util.Scanner;

public class CodeUp2608 {	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int pow = (int)Math.pow(2, num);
		int idx;
		char[] cArr = new char[num], tmp;
		Arrays.fill(cArr, 'O');

		for(int i=0; i<pow; i++)	{	
			tmp = Integer.toBinaryString(i).toCharArray();
			idx = Integer.toBinaryString(i).toCharArray().length;

			for(int j=0, k=idx-1; j<idx; j++, k--)	{
				if(tmp[j]=='0')	cArr[k] = 'O';
				else if(tmp[j]=='1')	cArr[k] = 'X';
				
			}
			
			for(int j=cArr.length-1; j>=0; j--)	
				System.out.print(cArr[j]);
			System.out.println();			
		}

	}
}