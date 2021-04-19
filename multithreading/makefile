
GCC=		gcc $(CCFLAGS)
EXAMPLE=	multithreading.o
MUTEX =		mutex.o
SEMAPHORE = sem.o
OBJS =		$(EXAMPLE) $(MUTEX) $(SEMAPHORE)

LIBS=		-lpthread

CCFLAGS= -g

all:		multithreading mutex sem

multithreading:	$(EXAMPLE)
		$(GCC) -o multithreading $(EXAMPLE) $(LIBS)

mutex:	$(MUTEX)
		$(GCC) -o mutex $(MUTEX) $(LIBS)

sem:	$(SEMAPHORE)
		$(GCC) -o sem $(SEMAPHOREC) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

hardclean:
		rm -f $(OBJS) $(OBJS:.o=.d) multithreading mutex sem
