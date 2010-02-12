VERSION = 0.0.1
NAME    = lolibc

CC     = clang
AR     = ar
CFLAGS = -fPIC -Wall -Wextra -Winline -Wno-long-long -nostartfiles -nostdlib -nodefaultlibs -fno-builtin -I./include

ifdef 32bit
CFLAGS += -m32
endif

DIR = sources

FILES = ${DIR}/string.o

ARCH = x86

ifeq ("${ARCH}", "x86")
x86_DIR = sources/arch/x86

FILES += ${x86_DIR}/string.o
endif

all: features $(FILES)
	${CC} ${CFLAGS} -shared -Wl,-soname,lib${NAME}.so.${VERSION} -o lib${NAME}.so.${VERSION} $(FILES)
	${AR} rcs liblolibc.a $(FILES)

features:
	utils/features.sh "${ARCH}"

clean:
	rm -f liblolibc.so.${VERSION}
	rm -f liblolibc.a
	find . | egrep "\.o" | xargs rm -f

help:
	@echo make ARCH={x86}
