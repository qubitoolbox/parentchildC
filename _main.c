
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
  //rows and columns 
  int r;
  int c;
  //pointers of the new img
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

/*
 * This method rotates a 24-bit, uncompressed .bmp file that has been read
 * in using readFile(). The rotation is expressed in degrees and can be
 * positive, negative, or 0 -- but it must be a multiple of 90 degrees
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 * rotation - a positive or negative rotation,
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows
 * newcols  - the new number of cols
 */
int rotate(PIXEL* original, int rows, int cols, int rotation,
	   PIXEL** new, int* newrows, int* newcols)
{
  /* THIS IS THE METHOD THAT YOU SHOULD WRITE */
  int c;
  int r;
	  
  //int option;
  switch(rotation)	
  {
    case 360:
      *newrows = rows;
      *newcols = cols;
      *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
    
      for (r=0; r < rows; r++)
      {
      	
        for (c = 0; c<cols; c++)
        {
          PIXEL* o = original + r * cols + c;
	  PIXEL* n = (*new) + r*cols + c;
	  *n=*o;
        }
      }
    break;
    case 270:
      			  
      *newrows = cols;
      *newcols = rows;
      *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
      for (r=0; r < rows; r++)
      {
        for (c=0; c < cols; c++) 
  	{
           PIXEL* o = original + r*cols + c;
           PIXEL* n = (*new) + (cols-c-1)*rows + r;
	   *n = *o;
	}
      }
		  
    break;
    case 180:
      *newrows = cols;
      *newcols = rows;
      *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
      for (r=0; r < rows; r++)
      {
        for (c=0; c < cols; c++) 
	{
 
          PIXEL* o = original + r * cols + c;
          PIXEL* n = (*new) + (rows-r)*cols - (c+1);
	  *n = *o;
	}
      }
      break;
      case 90:
        *newrows = cols;
        *newcols = rows;
        *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
	for (r=0; r < rows; r++)
	{
          for (c=0; c < cols; c++) 
	  {
         
            PIXEL* o = original + r*cols + c;
            PIXEL* n = (*new) + (cols-c-1)*rows + r;
	    *n = *o;
           }
	}		  
      break;
  }
  return 0;
}
	
/*
 * This method rotates a 24-bit, uncompressed .bmp file that has been read
 * in using readFile(). The rotation is expressed in degrees and can be
 * positive, negative, or 0 -- but it must be a multiple of 90 degrees
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 * rotation - a positive or negative rotation,
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows
 * newcols  - the new number of cols
 */
	
	
int rotatenegative(PIXEL* original, int rows, int cols, int rotation,
	   PIXEL** new, int* newrows, int* newcols)
{
  //columns and rows
  int c;
  int r;
	  
	//int option;
  switch(rotation)	
  {
    case -270:			  
      *newrows = cols;
      *newcols = rows;
      *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
       for (r=0; r < rows; r++)
       {
         for (c=0; c < cols; c++) 
         {
         PIXEL* o = original + r*cols + c;
         PIXEL* n = (*new) + (cols+c+1)*rows - r;
	 *n = *o;
         }
       }
    break;
    case -180:
      *newrows = cols;
      *newcols = rows;
      *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
      for (r=0; r < rows; r++)
      {
        for (c=0; c < cols; c++) 
	{
          PIXEL* o = original + r * cols + c;
          PIXEL* n = (*new) + ((rows-r-1)*cols + c);
	  *n = *o;
        }
      }
    break;
    case -90:
      *newrows = cols;
      *newcols = rows;
      *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
      for (r=0; r < rows; r++)
      {
        for (c=0; c < cols; c++) 
	{
          PIXEL* o = original + r*cols + c;
          PIXEL* n = (*new) + ((rows-r-1)*cols+ (c-1));
	  *n = *o;
	}
      }
		  
    break;
 
  return 0;
  }
}

/*
 * This method Vertically flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile().
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */

int verticalflip (PIXEL *original, PIXEL **new, int rows, int cols)
{
  /* THIS IS THE METHOD THAT YOU SHOULD WRITE */
  
  int row, col;

  if ((rows <= 0) || (cols <= 0)) return -1;

  *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));

  for (row=0; row < rows; row++)
  { for (col=0; col < cols; col++) {
      PIXEL* o = original + row*cols + col;
      //PIXEL* n = (*new) + row*cols + (cols-1+row);
      PIXEL* n = (*new) + row * cols + (cols-1-col);// * rows+row;
      *n = *o;
 }
  }
  return 0;
}


/*
 * This method horizontally flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile().
 *
 * THIS IS GIVEN TO YOU SOLELY TO LOOK AT AS AN EXAMPLE
 * TRY TO UNDERSTAND HOW IT WORKS
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */
int flip (PIXEL *original,PIXEL **new, int rows, int cols)
{
  int row;
  int col;

  if((rows <= 0) || (cols <= 0)) return -1;
  //*newrows = rows;
  //*newcols = cols;
  *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));
  
  for (row =0; row < rows; row++)
    for(col = 0; col < cols; col++)
    {
      PIXEL* o = original + row * cols + col;
      PIXEL* n = (*new) + (cols-col-1)* cols + row;//(cols-1-col);// + col;//(cols-1-col);
      *n = *o;
    } 
  
  return 0;
}
