
GCC=		gcc $(CCFLAGS)
EXAMPLE=	multithreading.o
MUTEX =		mutex.o
OBJS =		$(EXAMPLE) $(MUTEX)

LIBS=		-pthread

CCFLAGS= -g

all:		multithreading mutex

multithreading:	$(EXAMPLE)
		$(GCC) -o multithreading $(EXAMPLE) $(LIBS)

mutex:	$(MUTEX)
		$(GCC) -o mutex $(MUTEX) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

hardclean:
		rm -f $(OBJS) $(OBJS:.o=.d) multithreading mutex