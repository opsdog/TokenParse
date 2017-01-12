CC= gcc

CFLAGS=
COPTS=
INCLUDEDIRS=
LINKOPTS=

##
##  for debugging
##

# DEBUGFLAGS= -DDEBUG

TokenParseTargets= GetNextToken.o ReadLine.o ReadLine2.o ReadLine3.o ReadLine4.o \
	StripDelim.o

.c.o:
	$(CC) -c ${CFLAGS} ${COPTS} ${INCLUDEDIRS} ${DEBUGFLAGS} $<

all: TokenParse.o

##
##  token parsing "library"
##

GetNextToken.o: GetNextToken.c
	$(CC) -c -o GetNextToken.o GetNextToken.c ${CFLAGS} ${COPTS} ${DEBUGFLAGS}

ReadLine.o: ReadLine.c
	$(CC) -c -o ReadLine.o ReadLine.c ${CFLAGS} ${COPTS} ${DEBUGFLAGS}

ReadLine2.o: ReadLine2.c
	$(CC) -c -o ReadLine2.o ReadLine2.c ${CFLAGS} ${COPTS} ${DEBUGFLAGS}

ReadLine3.o: ReadLine3.c
	$(CC) -c -o ReadLine3.o ReadLine3.c ${CFLAGS} ${COPTS} ${DEBUGFLAGS}

ReadLine4.o: ReadLine4.c
	$(CC) -c -o ReadLine4.o ReadLine4.c ${CFLAGS} ${COPTS} ${DEBUGFLAGS}

StripDelim.o: StripDelim.c
	$(CC) -c -o StripDelim.o StripDelim.c ${CFLAGS} ${COPTS} ${DEBUGFLAGS}

TokenParse.o: ${TokenParseTargets}
	ld -r -o TokenParse.o ${TokenParseTargets} && echo



install: TokenParse.o
	cp TokenParse.h /Users/douggreenwald/include/
	cp TokenParse.o /Users/douggreenwald/lib/ && echo

clean:
	/bin/rm -f *.o *~ \#* core
	/bin/rm -f ${Targets}
	/bin/rm -f TokenParse.o && echo

##
##  depend relationships
##

GetNextToken.o: GetNextToken.c
ReadLine.o: ReadLine.c
ReadLine2.o: ReadLine2.c
ReadLine3.o: ReadLine3.c
ReadLine4.o: ReadLine4.c
StriDelim.o: StripDelim.c
TokenParse.o: ${TokenParseTargets}
