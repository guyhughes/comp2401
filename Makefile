.PHONY: default valgrind tags
default: clean tags
	gcc -Wall -Wextra -std=c99 -o out t05.c t05defs.c -g
valgrind: default
	valgrind --tool=memcheck --leak-check=full ./out
clean:
	rm -f ./out
tags:
	ctags -f .tags -R .
