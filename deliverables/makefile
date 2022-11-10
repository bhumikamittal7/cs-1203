#comment
CC = gcc
CFLAGS = -Wall -g3
all:
LDFLAGS = -lm
TARGET = main
OBJS = main.o
hello: hello.o hlib.o
hello.o: hello.c hlib.h
hlib.o: hlib.c hlib.h
$(CC) $(CFLAGS) $@ $^ $(LDFLAGS) -o $@
clean:
rm -f $(TARGET) $(OBJS)

