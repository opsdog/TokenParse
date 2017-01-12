/*

    very specifc program to read a line of CSV that is quoted and has
    embedded newlines

    will retain the commas, strip the quotes, and remove the embedded 
    newlines

    also will replace the microsoft long-dash special characters and the
    being and end double quote special characters

*/

/*
#undef DEBUG
#define DEBUG
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TokenParse.h"

void ReadLine3(char *Line, int FileDes, int *Status)
{

  int LineLength, RetVal;
  int InQuote;
  unsigned char Char;

#ifdef DEBUG
  printf("==>  ReadLine3:  entry\n");
  printf("==>  ReadLine3:  entry %d\n",FileDes);
  printf("==>  ReadLine3:  entry %d\n",*Status);
#endif

  LineLength = 0; InQuote = 0;
  
  RetVal=read(FileDes,&Char,1);
  if (RetVal == 0) {
    EndOfFile=1;
    /*    exit(0);*/
  }

  /*  while ( (Char != (char)10) && (RetVal != 0) ) {*/
  while ( (RetVal != 0) && (RetVal != -1) ) {
    if ( Char == 34 ) {
#ifdef DEBUG
      printf("Found a quote - InQuote is %d\n",InQuote);
#endif
      if ( InQuote == 0 )
	InQuote = 1;
      else
	InQuote = 0;
      RetVal=read(FileDes,&Char,1);
    }
    else {
#ifdef DEBUG
      printf("Found a %c\n",Char);
#endif
      if ( Char == 10 )  /*  if newline  */
	if ( InQuote == 1 ) {
	  Line[LineLength]=' ';
	  LineLength++;
	  RetVal=read(FileDes,&Char,1);
	}
	else {
	  RetVal= -1;
	}
      else {
	if ( Char == 150 )  /*  odd dash  */
	  Line[LineLength]='-';
	else
	  if ( Char == 147 )  /*  begin doub quote  */
	    Line[LineLength]=' ';
	  else
	    if ( Char == 148 )  /*  end doub quote  */
	      Line[LineLength]=' ';
	    else
	      if ( Char == 13 )  /*  Control-M  */
		Line[LineLength]=' ';
	      else
		Line[LineLength]=Char;

	LineLength++;
	RetVal=read(FileDes,&Char,1);
      }
    }  /*  else if quote  */
  }

#ifdef DEBUG
  printf("==>  ReadLine3:  LineLength %d\n",LineLength);
#endif

  Line[LineLength]='\0';
  *Status = LineLength;
  if (RetVal == 0) { EndOfFile = 1; *Status = -1; }

#ifdef DEBUG
  printf("==>  ReadLine3:  exit\n");
#endif
}
