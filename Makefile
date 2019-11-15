CSRCS=$(wildcard *.c)
COBJS=$(patsubst %.c,%.o,$(CSRCS))
EXEC=$(patsubst %.c,%, $(word 1, $(CSRCS)))

CFLAGS=-std=c99 -g -Wall -pedantic
LDFLAGS=-lm

all: build

build: $(EXEC)

lib: lib$(EXEC).so

lib$(EXEC).so: $(CSRCS)
	$(CC) -shared -o $@ $^ -fPIC

%: %.c
	@echo -e '\e[1;34mCompilation...\e[m'
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

clean:
	@echo -e '\e[1;34mCleaning...\e[m'
	$(RM) $(EXEC) *.o a.out lib$(EXEC).so

.PHONY: all format build lib
