
A=.a
O=.o
E=
CC=cc
I=include
CFLAGS=-g -I$I
LDFLAGS=-g
LD=cc
AS=as
AR=ar -ruv
RANLIB=ranlib
DIFF=diff
RM=rm -f
BUILDDIR=/home/spzhu/github/Cii/build

#EXTRAS=$(BUILDDIR)/memcmp$O $(BUILDDIR)/memmove$O $(BUILDDIR)/strncmp$O
EXTRAS=$(BUILDDIR)/memcmp$O $(BUILDDIR)/strncmp$O

B=$(BUILDDIR)/
#B=/home/spzhu/github/Cii/build/


OBJS=	$Bmem$O

EXAMPLES=	$BmemTest$E

all::	$Blibcii$A $(EXAMPLES) 

$Blibcii$A::	$(OBJS) $(EXTRAS)
		$(AR) $@ $(OBJS) $(EXTRAS); $(RANLIB) $@ || true


$Bmem$O:		src/mem.c;	$(CC) $(CFLAGS) -c -o $@ src/mem.c

$Bmemcmp$O:		src/memcmp.c;	$(CC) $(CFLAGS) -c -o $@ src/memcmp.c
#$Bmemmove$O:	src/memmove.c;	$(CC) $(CFLAGS) -c -o $@ src/memmove.c
$Bstrncmp$O:	src/strncmp.c;	$(CC) $(CFLAGS) -c -o $@ src/strncmp.c

$BmemTest$O:	examples/memTest.c;		$(CC) $(CFLAGS) -c -o $@ examples/memTest.c

$BmemTest$E: 	$BmemTest$O $Blibcii$A;		$(LD) $(LDFLAGS) -o $@ $BmemTest$O $Blibcii$A


clean::
		$(RM) $B*$O
		$(RM) $(EXAMPLES)
