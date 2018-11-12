
#include <stdlib.h>
#include <stdio.h>
#include "bmplib.h"
#include "bmplib.c"

/*
 * This method enlarges a 24-bit, uncompressed .bmp file
 * that has been read in using readFile()
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the original number of rows
 * cols     - the original number of columns
 *
 * scale    - the multiplier applied to EACH OF the rows and columns, e.g.
 *           if scale=2, then 2* rows and 2*cols
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows (scale*rows)
 * newcols  - the new number of cols (scale*cols)
 */
int enlarge(PIXEL* original, int rows, int cols, int scale,
	    PIXEL** new, int* newrows, int* newcols)
{
  /* THIS IS THE METHOD THAT YOU SHOULD WRITE */
  
  int r;
  int c;
  
  *newrows = scale * rows;
  *newcols = scale * cols;
  
  *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
  
  for (int row=0; row<rows; row++)
  {
    for (int i=0; i<scale; i++)
	{
      for (int col=0; col<cols; col++)
	  {
	    for(int j=0; j<scale; j++)
		{
			PIXEL* o = original+row*cols+col;
			PIXEL* n = (*new) + row*cols*scale*scale + cols*scale*i + col*scale + j;
			*n = *o;
		}
	  }
	}
	    
  }
  
  return 0;
}
