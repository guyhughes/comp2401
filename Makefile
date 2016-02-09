CFLAGS=-Wall -Wextra -Wpedantic -Werror -Wshadow -Wstrict-overflow -fno-strict-aliasing -std=gnu11 -g
default:
clean:
	find -maxdepth 1 \( \( -type f -regextype posix-extended -regex '.*\.(pyc|tar)' \) -o \( -type f -perm /a=x -a -regextype posix-extended -! -regex '.*\.(py|sh|bash|csh|zsh)' \) \) -ok rm {} \;
