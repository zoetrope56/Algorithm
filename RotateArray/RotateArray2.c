#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 5 
#define ROW 5

int array[ROW][COL]={{0,}};

int main(void)
{
  int i, j;
  int t1, t2;
  int diff=0;
  int count=0;

  printf("--------ORIGIN---------\n");
  for(i=0; i<ROW; i++){
	for(j=0; j<COL; j++){
	  array[i][j]=j+i*ROW+1;
	  printf("%3d ",array[i][j]);
	}
	printf("\n");
  }

  printf("\n\n--------ROTATED---------\n");
  while(count < 8){
	diff = count/4;
	switch(count%4){
	  case 0:
		for(i=COL-diff-1; i>diff; i--){
		  if(i==COL-diff-1){
			t1 = array[diff][i];
			array[diff][i] = array[diff][i-1];
		  } else {
			array[diff][i] = array[diff][i-1];
		  }
		}
		break;
	  case 1:
		for(i=diff+1; i<ROW-diff; i++){
		  if(i==diff+1){
			t2 = array[ROW-i][COL-i];
			array[ROW-i][COL-diff-1] = array[ROW-i-1][COL-diff-1];
		  } else {
			array[ROW-i][COL-diff-1] = array[ROW-i-1][COL-diff-1];
		  }
		}
		array[diff+1][COL-diff-1] = t1;
		break;
	  case 2:
		for(i=diff; i<COL-diff-1; i++){
		  if(i==diff){
			t1 = array[ROW-diff-1][diff];
			array[ROW-diff-1][diff-1+i] = array[ROW-diff-1][diff+1];
		  } else {
			array[ROW-diff-1][diff-1+i] = array[ROW-diff-1][diff+i];
		  }
		}
		array[ROW-diff-1][COL-1-diff-1] = t2;
		break;
	  case 3:
		for(i=COL-diff-1; i>diff; i--){
		  array[ROW-1-diff-i][diff] = array[ROW-diff-i][diff];
		}
		array[ROW-1-diff-1][diff] = t1;
		break;
	}
	count+=1;
  }

  array[0][1]=1;

  for(i=0; i<ROW; i++){
	for(j=0; j<COL; j++){
	  printf("%3d ",array[i][j]);
	}
	printf("\n");
  }
  


  return 0;
}
