#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int c = 0;
  while (line[0]==0 || c < length) {
	  //slide tiles left
	  if(line[0]==0) {
		  line[0]=line[1];
		  line[1]=line[2];
		  line[2]=line[3];
		  line[3]=0;
	  }
  }
  // combine tiles as required

  return 0;
}
