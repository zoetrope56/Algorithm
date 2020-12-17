class Solution {
	public static int[] solution(int[] array, int[][] commands) {
		int[] answer = new int[commands.length];
		int tmp, x=0;

		while(x<commands.length)  {
			int[] arr = commands[x];			
			int[] res = new int[arr[1]-arr[0]+1];
			
			for(int i=arr[0]-1, k=0; i<arr[1]; i++, k++)
				res[k] = array[i];

			for(int i=0; i<res.length; i++)	{	// sort
				for(int j=i+1; j<res.length; j++)	{
					if(res[i] >= res[j])	{
						tmp = res[j];
						res[j] = res[i];
						res[i] = tmp;
					}
				}
			}			

			answer[x] = res[arr[2]-1];
			x++;
		}

		return answer;
	}
}
