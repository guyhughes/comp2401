CFLAGS := -Wall -Wextra -pipe -g -ggdb -g3 -Wmissing-prototypes -std=c99

all:	t10-fork t10-threads
	make t10-fork t10-threads

t10-fork:	t10-fork.c
	gcc -o t10-fork t10-fork.c

t10-threads:	t10-threads.c
	gcc -pthread -o t10-threads t10-threads.c -lm

t10-gold: t10-gold.c
	gcc -pthread -o t10-gold t10-gold.c

clean:
	rm t10-threads t10-fork
