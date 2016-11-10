CC = gcc
CFLAGS = -Wall -ansi -pedantic -o2

.PHONY: clean

ep4: tabelaSimbolo.o tabelaSimbolo_VD.o buffer.o tipos.o tabelaSimbolo_LD.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *~ ep4
