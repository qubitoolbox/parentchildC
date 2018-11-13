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
  static char usage[] = "usage:";
  static char usage1[] = "usage cont'd";
  int r; //rows
  int c; // columns
  int nr;
  int nc;
  int menu;
  PIXEL *b;
  PIXEL *nb;
  char filein[20];
  char fileout[20];
  char* finn;// = stdin
  char* foutt;// = stdout;
  
  int scaleparam = 0;
  int rotateparam = 0;
  char* outparam;
  int debug = 0;
  finn = NULL;
  foutt = NULL;
  outparam = NULL;
  
  while ((menu=getopt(argc, argv, "srvfo:")) != -1)
  {  

    switch(menu)
    {
		
      case 's':
         
	sflag = 1;
      
      break;
      case 'r':
        rflag = 1;
      break;
      case 'v':
 	vflag = 1;	
      break;
      case 'f':
        fflag = 1;
      break;
       	  /*
	  case '?':
	    err = 1;
	  break;*/
      case 'o':
        oflag = 1;
        optargr = optarg;
        //printf("something here %s", optargr);
      break;
      default:
        negval = atoi(argv[optind]);
        //printf("rotate neg %d", negval);
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
  else
    rotateparam = negval;
  if (optind <= argc)
  {
    for (; optind <= argc; optind++)
    {
      finn = argv[optind-1];
      printf("\n Input file has been read %s\n", finn);
    }
  }
  else
  {
    printf("\nInput file name missing!!\n");
    printf("Type input file name: ");
    scanf("%s\0", filein);
    printf("file has been read manually.");
  }
  if (finn != NULL)
    readFile(finn, &r, &c, &b);
  else
    readFile(filein, &r, &c, &b);
