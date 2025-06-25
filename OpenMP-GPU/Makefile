CC = nvc
CFLAGS = -mp=gpu -Minfo=mp

PROGRAMS = pi

all: $(PROGRAMS)

pi: pi.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGRAMS)
