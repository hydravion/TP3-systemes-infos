CFLAGS = -Wall -c
LFLAGS = -lssl -lcrypto
OBJS = main.o compute_hash.o parse_options.o


hash: $(OBJS)
	gcc $(OBJS) -o $@ $(LFLAGS)

main.o: main.c compute_hash.h parse_options.h
	gcc $(CFLAGS) main.c -o $@

compute_hash.o: compute_hash.c compute_hash.h
	gcc $(CFLAGS) compute_hash.c -o $@

parse_options.o: parse_options.c parse_options.h
	gcc $(CFLAGS) parse_options.c -o $@

clean:
	rm ./*.o hash
