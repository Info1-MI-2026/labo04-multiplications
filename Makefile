CSRCS=$(wildcard *.c)
COBJS=$(patsubst %.c,%.o,$(CSRCS))
EXEC=$(patsubst %.c,%, $(word 1, $(CSRCS)))

CFLAGS=-std=c11 -g -Wall -pedantic
LDFLAGS=-lm

all: build

build: $(EXEC)

%: %.c
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS)

clean:
	$(RM) $(EXEC) *.o a.out lib$(EXEC).so

.PHONY: all format build lib
