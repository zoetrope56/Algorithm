#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 6 
#define ROW 6

#define SHUFFLE_COUNT 80 

int main(void)
{
  int i, j;
  int idx_a, idx_b;
  int temp_rand, temp_origin;
  int numbers[COL][ROW]={{0,},};

  srand(time(NULL));

  // Init array
  for(i=0; i<COL; i++){
	for(j=0; j<ROW; j++){
	  numbers[i][j] = i*ROW + (j+1);
	  printf("%4d ",numbers[i][j]);
	}
	printf("\n");
  }

  // Shuffle
  for(i=0; i<SHUFFLE_COUNT; i++){
	temp_rand = rand() % (COL*ROW);
	printf("shuffling, %d\n", temp_rand);
	idx_a = temp_rand / ROW;
	idx_b = temp_rand % ROW;
	if(idx_a == idx_b){
	  temp_origin = numbers[idx_a][idx_b];
	  numbers[idx_a][idx_b] = numbers[COL-idx_a-1][ROW-idx_b-1];
	  numbers[COL-idx_a-1][ROW-idx_b-1] = temp_origin;
	}else{
	  temp_origin = numbers[idx_a][idx_b];
	  numbers[idx_a][idx_b] = numbers[idx_b][idx_a];
	  numbers[idx_b][idx_a] = temp_origin;
	}
  }

  // Print
  for(i=0; i<COL; i++){
	for(j=0; j<ROW; j++){
	  printf("%4d ", numbers[i][j]);
	}
	printf("\n");
  }
}
