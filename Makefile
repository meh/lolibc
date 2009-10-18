VERSION = 0.0.1
NAME    = lolibc

CC     = gcc
CFLAGS = -fPIC -Wall -Wextra -Wno-long-long -pedantic -nostdlib -nodefaultlibs -fno-builtin -I./include

ifdef 32bit
CFLAGS += -m32
endif

DIR = sources

FILES = ${DIR}/string.o

ARCH = x86

ifeq ("${ARCH}", "x86")
CFLAGS += -D_LOLIBC_X86

x86_DIR = sources/arch/x86

FILES += ${x86_DIR}/string.o
endif


all: $(FILES)
	gcc ${CFLAGS} -shared -Wl,-soname,lib${NAME}.so.${VERSION} -o lib${NAME}.so.${VERSION} $(FILES)
	ar rcs liblolibc.a $(FILES)

clean:
	rm -f liblolibc.so.${VERSION}
	rm -f liblolibc.a
	find . | egrep "\.o" | xargs rm -f
