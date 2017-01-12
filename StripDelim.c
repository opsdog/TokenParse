/*

  remove any leading/doubled delimiters from a line of text

*/

/*
#undef DEBUG
#define DEBUG
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char *StripDelim(char DeLim, char *srcString)
{

  int srcStringLength;
  int srcIndex;
  int rtnIndex;

  char chrPrevious;

  char *rtnString;

#ifdef DEBUG
  printf("==>  StripDelim:  entry\n");
  printf("==>  StripDelim:  entry -->%c<--\n",DeLim);
  printf("==>  StripDelim:  entry -->%s<--\n",srcString);
#endif

  /*  set stuff up  */

  srcStringLength = strlen(srcString);
  rtnString = (char *)malloc(srcStringLength);
  rtnString[0] = '\0';
  srcIndex = 0;

  /*  if first char is the delimiter, strip it and any that follow  */

  while ( ( ( srcString[srcIndex] == DeLim ) |
	    ( srcString[srcIndex] == 9     ) )  &
	  ( srcString[srcIndex] != '\0'  ) ) {
    srcIndex++;
  }  /*  while consuming leading delimiter(s)  */

  /*  out of leading delim loop - next char should be non-DeLim  */

#ifdef DEBUG
  printf("==>  StripDelim:  out of leading burn (%d) -->%c<--\n",
	 srcString[srcIndex], srcString[srcIndex]);
#endif

  /*  now strip embedded duplicated delims  */

  rtnIndex = 0;
  while ( srcString[srcIndex] != '\0' ) {

    if ( srcString[srcIndex] != DeLim ) {
      rtnString[rtnIndex] = srcString[srcIndex];
      rtnIndex++;
    } else {
      rtnString[rtnIndex] = DeLim;
      rtnIndex++;
      while ( (srcString[srcIndex] == DeLim ) & ( srcString[srcIndex] != '\0' ) )
	srcIndex++;
      rtnString[rtnIndex] = srcString[srcIndex];
      rtnIndex++;
    }

    if ( srcString[srcIndex] != '\0' )
      srcIndex++;
  }  /*  while stripping embedded duplicated delims  */

#ifdef DEBUG
  printf("==>  StripDelim:  out of dedup -->%s<--\n",rtnString);
#endif

  strcpy(srcString,rtnString);

}
