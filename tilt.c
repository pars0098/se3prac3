#include <stdio.h>
#include "2048.h"

int tilt_board_left(int length, int **board) {
	//Tilt each row of the board left
	int line[length];
	int i = 0;
	while (i < length)
	{
		int j = 0;
		while(j < length) {
			line[j] = board[i][j];
			j++;
		}
		tilt_line_left(length, line);
		i++;
	}
	return 0;
}

int tilt_line_left(int length, int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int c = 0;
  int p = 0;
  while (c < length) {
	  //slide tiles left
		if (line[c]!=0) {
			line[p]=line[c];
			if (p!=c) {
				line[c]=0;
			}
			p++;
		}
		c++;
	}

	// combine tiles as required
	c = length - 1;
	while (c > 0) {
		if (line[c-1]!=0 && line[c-1]==line[c]) {
			line[c-1]+=line[c];
			int d = c;
			while (d < length) {
				if (d < length-1) {
					line[d]=line[d+1];
				}
				else {
					line[d]=0;
				}
				d++;
			}
			c--;
		}
		c--;
	}

  return 0;
}
