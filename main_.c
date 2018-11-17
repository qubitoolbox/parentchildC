#include "_main.c"

//main
int main(int argc, char **argv)
{
	
  extern char *optarg;
  extern int optind;
  char* optargr; //retrieves opartg value for later use
  int optindex;
  //
  int err =0;
  int sflag; //scale image
  int rflag; //rotate
  int vflag; //flip vertically
  int fflag; //flip horizontally
  int oflag; //output file
  int negval; //
  int negflag;
  int tempflag = 0;
  static char usage[] = "usage: ./bmptool [-s scale | -r degree |-f|-v][-o output] [inputfile]";
  static char usage1[] = "usage cont'd";
  int r; //rows
  int c; //columns 
  int nr;//newrows
  int nc;//newcols
  int menu;
  PIXEL *b;
  PIXEL *nb;
  char filein[12];
  char fileout[3];
  char* finn;// = stdin
  char* foutt;// = stdout;
  
  int scaleparam = 0; //initial arg for scaling image
  int rotateparam = 0;//arg for rotating image
  char* outparam; //pointer to the output file array
  int debug = 0;
  finn = NULL; //input file
  foutt = NULL; //output file
  outparam = NULL;//= fileout;
  
  while ((menu=getopt(argc, argv, "srvfo:")) != -1)
  {  

    switch(menu)
    {
		
      case 's':
        if (sflag)
        {  
          printf("This option is already set\n");
          printf("Try with single of same flag\n");
          return -1;
        }
	sflag = 1;
      break;
      case 'r':
        rflag = 1;
      break;
      case 'v':
 	vflag = 1;	
      break;
      case 'f':
        if (fflag)
        {
          printf("This option is already set\n");
          printf("Try with single parameter of same flag");
          return -1; 
        }
        fflag = 1;
      break;
      case 'o':
        oflag = 1;
        optargr = optarg;
        //printf("something here %s", optargr);
      break;
      default:
        negval = atoi(argv[optind-1]);
        printf("rotate neg %d\n", negval);
        negflag = 1;
      break;
	  
    }
  }
	 //retrieves the value that user enters 
	 //for enlarging image
  if(sflag)
    scaleparam = atoi(argv[optind++]);
     //value for performing rotation
  if(rflag && !negflag)
    rotateparam = atoi(argv[optind++]);
  else if (negflag)
    rotateparam = negval;
  //retrieve the file name for input
  if (optind <= argc )
  {
    for (; optind <= argc; optind++)
    {
      finn = argv[optind-1];
      printf("\n Input file has been read %s\n", finn);
    }
  }
  //decide if input will be from oflag or
  //stdin typed manually by user 
  if (finn != NULL)
  {  readFile(finn, &r, &c, &b);}
  else
  { 
    scanf("Type input file name:%s\0", filein); 
    readFile(filein, &r, &c, &b);}
  
  //get the value of the output file if
  //oflag is set by user		
  //if(oflag)
  //{
    //printf("\nOpps... Something went wrong.\n");
    //printf("Type the output file name: ");
    //scanf("%s\0", fileout);
    //foutt = optargr;
    //foutt = &fileout[0];
  //}
  //else
  /*{
    printf("Output file name is missing\n");
    printf("Type a file name for output:");
    scanf("%s\0", fileout);
    //outparam = fileout; //set array to pointer
  }*/
  //invokes function for scaling image
  if(sflag)
  {
    enlarge(b, r, c, scaleparam, &nb, &nr, &nc);
    r = nr;
    c = nc;	
  }
  //invokes function for rotation
  //only if a negative input is not detected
  if(rflag && !negflag)
  {
    rotate(b, r, c, rotateparam, &nb, &nr, &nc);
    r = nr;
    c = nc;
  }
  else //invoke negative parameters for rotation
  {
    rotatenegative(b, r, c, rotateparam, &nb, &nr, &nc);
    r = nr;
    c = nc;
  }
  if(vflag)
  {
    //verticalflip(b, &nb, r, c, &nb, &nr, &nc);
  }
  if(fflag)
  {
    flip(b, &nb, r, c);
  }

  if (oflag)
  {
    foutt = optargr;
  }
  else
  {
    printf("Output file name is missing\n");
    printf("Type output file name");
    scanf("%s\0", fileout);
  }
  if(foutt != NULL)
  {
    printf("foutt being used");	 
    writeFile(foutt, r, c, nb);
  }else if(fileout != NULL)
   { printf("outparam being used");
    writeFile(fileout, r, c, nb);}
  free(b);
  free(nb);
  

//if (fflag == 0) {	/* -f was mandatory */
    //fprintf(stderr, "%s: missing -s option\n", argv[0]);
    //fprintf(stderr, usage, argv[0]);
//	exit(1);
  //} else 
	  
	if ((optind+1) > argc) {	
	// need at least one argument (change +1 to +2 for two, etc. as needeed) 
	printf("optind = %d, argc=%d\n", optind, argc);
	fprintf(stderr, "%s: missing name\n", argv[0]);
	fprintf(stderr,"\n", usage, argv[0]);
	exit(1);
  } else if (err) {
	fprintf(stderr, "\n", usage, argv[0]);
	exit(1);
  }
	/* see what we have */
	//printf("debug = %d\n", debug);
	printf("sflag = %d\n", sflag);
	printf("vflag = %d\n", vflag);
	printf("rflag = %d\n", rflag);
	printf("fflag = %d\n", fflag);
	printf("oflag = %d\n", oflag);
	
	//printf("fname = \"%s\"\n", fname);
	//printf("sname = \"%s\"\n", sname);
	
  if (optind < argc){	/* these are the arguments after the command-line options */
    for (; optind < argc; optind++){
      printf("\nargument: \"%s\"\n", argv[optind]);
      printf("optind %d\n", optind);
      printf("%s", argv[optind + 1]);}
     }
  else
  {
    printf("no arguments left to process\n");
  }
  
  return 0;
}
