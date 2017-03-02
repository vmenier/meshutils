include make.inc
#include egads.inc

#
#IDIR = $(ESP_ROOT)/src/EGADS/include/
#LDIR = $(ESP_ROOT)/lib
#BDIR = .


ifdef NOTHREAD 
	CFLAG_MESHUTILS = $(CFLAGS) -DSERIAL 
else
	CFLAG_MESHUTILS = $(CFLAGS) -D_MTHREAD_ -DNDEBUG
endif   

OBJS = meshutils.o clean.o extraction.o GMFio.o libmesh6.o mesh.o modules.o option.o parser.o SU2io.o utils.o GMSHio.o tagbl.o \

all: meshutils meshutils.h

%.o: %.c 	$(CC) -c -g -ggdb $(CFLAG_MESHUTILS) -I. -I$(IDIR)  $<

meshutils:$(OBJS)
	$(CC) -g -ggdb $(CFLAGS) $(OBJS) $(OBJLIB) -o ./meshutils $(LIBredist) -lm $(RPATH) -L$(LDIR)  -lm

clean:
	rm -f *.o 

