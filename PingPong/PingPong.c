#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const unsigned char MAX = 30;
const unsigned char MIN = 0;
const unsigned char HOP = 10;

const unsigned int COUNT = 100;

int CURRENT = 0;

int main(void)
{
  srand((unsigned)time(NULL));
  unsigned char FLAG = 0;
  int cnt, random;
  
  for(cnt=0; cnt<COUNT; cnt++){
	if(FLAG == 1){
	  CURRENT -= rand()%HOP+1;
	} else{
	  CURRENT += rand()%HOP+1;
	}
	if (CURRENT >= MAX){
	  CURRENT = MAX;
	  FLAG = 1;
	  printf("PING!\n");
	}
	else if (CURRENT <= MIN){
	  CURRENT = MIN;
	  FLAG = 0;
	  printf("PONG!\n");
	}
	printf("%3d : %d\n", cnt, CURRENT);
  }
  printf("END\n");
  return 0;
}
