CC     = gcc
CFLAGS = -Wall -Wextra
LIBS   = -fopenmp

PROGRAM = plb
SRCS    = $(wildcard *.c)
OBJS    = $(SRCS:.c=.o)

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

log: $(PROGRAM) measure.bash
	./measure.bash

plot: log
	gnuplot -p -e 'log="log";' -e 'plot log pt 7 w lp'

clean:
	rm -f $(PROGRAM) $(OBJS)

.PHONY: clean plot
