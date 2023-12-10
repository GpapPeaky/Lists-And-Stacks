CC=gcc
CFLAGS=-ansi -g

cs240StreamingService: main.c _error.c _stack.c _prints.c _filtered.c _movies.c _users.c  streaming_service.h
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f cs240StreamingService
