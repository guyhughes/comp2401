CFLAGS := -Wall -Wextra -Wpedantic -Wshadow -Wstrict-overflow
CFLAGS += -Wno-unused-parameter 
CFLAGS += -fno-strict-aliasing -std=c99
CFLAGS += -g -ggdb3 -g3 

.PHONY: default
default: clean tags runners-doublepointer runners-simple

.PHONY: tags
tags:
	ctags -f .tags -R .


runners.o: runners.c runners.h

runners-doublepointer: addRunner-doublepointer-method.o runners.o
	$(CC) $(CFLAGS) -o runners-doublepointer addRunner-doublepointer-method.o runners.o

runners-simple: addRunner-simple-method.o runners.o
	$(CC) $(CFLAGS) -o runners-simple addRunner-simple-method.o runners.o


.PHONY: clean
clean:
	rm -f runners *.o runners-doublepointer runners-simple
