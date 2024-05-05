CC = gcc
CFLAGS = -Wall -Wextra -DCTEST_ENABLE
LIB = libvvsfs.a
SRCS = image.c block.c
OBJS = $(SRCS:.c=.o)
EXEC = testfs

.PHONY: all clean pristine

all: $(EXEC)

$(EXEC): testfs.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(LIB): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

testfs.o: testfs.c image.h block.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) testfs.o $(EXEC) $(LIB)

pristine:
	rm -f $(OBJS) testfs.o $(EXEC) $(LIB)