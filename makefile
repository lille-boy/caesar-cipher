CC = gcc
CFLAGS = -I.
DEPS = caesar.h
OBJ = main.o caesar.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

caesar: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)
