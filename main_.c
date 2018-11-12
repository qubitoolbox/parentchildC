//argv contains an array of pointers
int main(int argc, char **argv)
{
	
  extern char *optarg;
  extern int optind;
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
  char* finn;// = stdin
  char* foutt;// = stdout;
  char filein[20];
  char fileout[20];
  int scaleparam = 0;
  int rotateparam = 0;
  char* outparam;
  int debug = 0;
  finn = NULL;
  foutt = NULL;
  outparam = NULL;
  
  while ((menu=getopt(argc, argv, "srvfo")) != -1)
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
	  break;
	  case '?':
	    negflag = atoi(argv[optind]);
		if (negflag == 0 && negflag < 0)
		{
			negval = 1;
			rotateparam = negflag;
		}
	}
  }
  
  
     //argc -= optind; // to throw error for no args
	 //argv += optind;
  
	 //retrieves the value that user enters 
	 //for enlarging image
	 if(sflag)
	   scaleparam = atoi(argv[optind++]);
     if(rflag && !negval)
	   rotateparam = atoi(argv[optind++]);
	   //if(rotateparam == -90 || rotateparam == -180)
	   //	   printf("success");
     if(oflag)
	   outparam = argv[optindex++];
    
	 if (optind <= argc)
		{
			for (; optind < argc; optind++)
			{
				finn = argv[optind];
				printf("\n%s first arg\n", finn);
			}
		}else
		{
			printf("Type file name: ");
			scanf("%s/0", filein);
		}
 
	 if(sflag)
	 {
		if (finn != NULL)
			readFile(finn, &r, &c, &b);
		else
			readFile(filein, &r, &c, &b);
	    enlarge(b, r, c, scaleparam, &nb, &nr, &nc);
		writeFile("12.bmp", r, c, nb);
	    free(b);
	    free(nb);
	 }
	 if(rflag)
	 {
		if (finn != NULL)
			readFile(finn, &r, &c, &b);
		else
			readFile(filein, &r, &c, &b);
	    rotate(b, r, c, rotateparam, &nb, &nr, &nc);
	    r = nr;
	    c = nc;
		writeFile("13.bmp", r, c, nb);
	    free(b);
	    free(nb);
	 }
	 if(vflag)
	 {
		if (finn != NULL)
			readFile(finn, &r, &c, &b);
		else
			readFile(filein, &r, &c, &b);
	    verticalflip(b, &nb, r, c);
	    free(b);
	    free(nb);
	 }
	 if(fflag)
	 {
		if (finn != NULL)
			readFile(finn, &r, &c, &b);
		else
			readFile(filein, &r, &c, &b);
	    flip(b, &nb, r, c);
		writeFile("2.bmp", r, c, nb);
	    free(b);
	    free(nb);
	 }
  

//if (fflag == 0) {	/* -f was mandatory */
    //fprintf(stderr, "%s: missing -s option\n", argv[0]);
    //fprintf(stderr, usage, argv[0]);
//	exit(1);
  //} else 
	  /*
	if ((optind+1) > argc) {	
	 need at least one argument (change +1 to +2 for two, etc. as needeed) 
	printf("optind = %d, argc=%d\n", optind, argc);
	fprintf(stderr, "%s: missing name\n", argv[0]);
	fprintf(stderr, usage, argv[0]);
	exit(1);
  } else if (err) {
	fprintf(stderr, usage, argv[0]);
	exit(1);
  }*/
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
		//printf("%s", argv[optind + 1]);}
	}}else
  {
	printf("no arguments left to process\n");
  }
 
  
  return 0;
}
