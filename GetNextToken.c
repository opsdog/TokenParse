/*
  function to return the next token from a string of tokens

  takes the value seperator and the string of tokens
*/

/*
#undef DEBUG
#define DEBUG
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char *GetNextToken(char DeLim, char *srcString)
{
  int srcStringLength,
    targetIndex,
    srcIndex;

  char *Token;

#ifdef DEBUG
  printf("==>  GetNextToken:  entry\n");
  printf("==>  GetNextToken:  entry %d\n",(int)srcString[0]);
  printf("==>  GetNextToken:  entry %s\n",srcString);
#endif

  /*  set stuff up  */

  srcStringLength = strlen(srcString);

#ifdef DEBUG
  printf("==>  GetNextToken:  source string length:  %d\n", srcStringLength);
#endif

  Token = (char *)malloc(srcStringLength);

  Token[0]='\0';
  srcIndex = 0;

  /*  find the first token and remove it from the beginning of srcString  */

  while ( ( srcString[srcIndex] != DeLim ) & ( srcString[srcIndex] != '\0' ) ) {
#ifdef DEBUG
    printf("==>  GetNextToken:    top of while %c (%d)\n",
	   srcString[srcIndex], srcIndex);
#endif
    Token[srcIndex] = srcString[srcIndex];

    srcIndex++;
  }  /*  while scanning for first token in srcString  */
  Token[srcIndex]='\0';
#ifdef DEBUG
  printf("==>  GetNextToken:  out of while %d\n",srcIndex);
#endif

  if (srcString[srcIndex] == '\0' )
    srcIndex--;
  srcIndex++;
  targetIndex = 0;

#ifdef DEBUG
  printf("==>  GetNextToken:  eating first token %d %d\n",srcIndex, targetIndex);
#endif

  while ( srcString[srcIndex] != '\0' ) {
    srcString[targetIndex] = srcString[srcIndex];

    srcIndex++;
    targetIndex++;
  }  /*  while removing first token  */
  srcString[targetIndex]='\0';


  /*  clean up and go home  */

#ifdef DEBUG
  printf("==>  GetNextToken:  source string length:  %d\n", srcStringLength);
  printf("==>  GetNextToken:  exit %s ->%s<-\n",Token,srcString);
#endif
  return(Token);

}
