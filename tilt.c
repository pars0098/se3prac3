#include <stdio.h>
#include "2048.h"

int tilt_board_left(int length, int **board) {
	//Tilt each row of the board left
	int line[length];
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++) {
			line[j] = board[i][j];
		}
		tilt_line_left(length, line*);
	}
}

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
  if (line[3]==line[4]) {
	  line[3]+=line[4];
	  line[4]=0;
  }
  else {
	  if (line[2]==line[3]) {
		  line[2]+=line[3];
		  line[3]=0;
	  }
	  else {
		  if (line[1]==line[2]) {
			  line[1]+=line[2];
			  line[2]=0;
		  }
	  }
  }

  return 0;
}
