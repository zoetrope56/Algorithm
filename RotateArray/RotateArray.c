#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 7

int main(void){

  int array[MAX] = {0,};
  int i, j;
  int count;
  int tmp;
  srand((unsigned)time(NULL));

  printf("Origin\n");
  for(i=0; i<MAX; i++){
	array[i] = rand()%10;
	printf("%3d ", array[i]);
  }
  printf("\nShift? >> ");
  scanf("%d", &count);
  
  for(i=0; i<count; i++){
	tmp = array[MAX-1];
	for(j=MAX-1; j>0; j--){
	  array[j]=array[j-1];
	}
	array[0] = tmp;
  }

  for(i=0; i<MAX; i++){
	printf("%3d ", array[i]);
  }
  printf("\nDone\n");

  return 0;
}
