/*

  function to read a line from the specified file descriptor

*/

/*
#undef DEBUG
#define DEBUG
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TokenParse.h"

void ReadLine2(char *Line, int FileDes, int *Status)
{
  int LineLength, RetVal;
  /*  char *TheLine;*/
  /*  char TheLine[2048];*/
  char Char;

#ifdef DEBUG
  printf("==>  ReadLine2:  entry\n");
  printf("==>  ReadLine2:  entry %d\n",FileDes);
  printf("==>  ReadLine2:  entry %d\n",*Status);
#endif

  /*  TheLine = (char *)malloc(2048);*/
  LineLength=0;
  
  RetVal=read(FileDes,&Char,1);
  if (RetVal == 0) {
    EndOfFile=1;
    /*    exit(0);*/
  }

  while ( (Char != (char)10) && (RetVal != 0) ) {
    Line[LineLength]=Char;
    LineLength++;
    RetVal=read(FileDes,&Char,1);
  }

#ifdef DEBUG
  printf("==>  ReadLine2:  LineLength %d\n",LineLength);
#endif

  Line[LineLength]='\0';
  *Status = LineLength;
  if (RetVal == 0) { EndOfFile = 1; *Status = -1; }

  /*  return(Line);*/

}
