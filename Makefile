VERSION = 0.0.1
NAME    = lolibc

CC     = gcc
CFLAGS = -fPIC -I./include

DIR = sources

FILES = ${DIR}/string.o

all: $(FILES)
	gcc -shared -Wl,-soname,lib${NAME}.so.${VERSION} -o lib${NAME}.so.${VERSION} $(FILES)

clean:
	find . | egrep "\.o" | xargs rm
