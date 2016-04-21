CFLAGS := -Wall -Wextra -Wpedantic -Wshadow -Wstrict-overflow
CFLAGS += -Wno-unused-parameter 
CFLAGS += -fno-strict-aliasing -std=c99
CFLAGS += -g -pipe -ggdb3 -g3 

.PHONY: default
default: clean tags runners

.PHONY: tags
tags:
	ctags -f .tags -R .


runners: runners.h runners.c

.PHONY: clean
clean:
	rm -f runners
