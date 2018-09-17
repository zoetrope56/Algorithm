#include <stdio.h>
#define MAX 10

int main(void){
  int array[MAX]={0,};
  int val=1, index=0, count=0, start=1, diff=0;
  int i;

  while(val<=MAX || !(index==MAX)){
	array[index]=val;
	printf("%3d ",array[index]);
	count++;
	val+=count+diff;

	if(val>MAX){
	  printf("\n");
	  diff++;
	  start+=diff+1;
	  val=start;
	  count=0;
	}
	index++;
  }
}

