#Subor: Makefile
#Autor: xondre12
#Fakulta: FIT VUT
#Uloha: 1 a 2
#Datum: 22.4.2020

CC=gcc
CFLAGS= -std=c99 -Wall -pedantic -Wextra

HTAB_H= htab.h htab_structures.h

OBJ= htab_size.o htab_find.o htab_bucket_count.o htab_clear.o htab_end.o htab_free.o htab_hash_fun.o htab_init.o htab_item_initialize.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_initialize.o extern.o htab_iterator_set_value.o htab_lookup_add.o htab_begin.o htab_iterator_next.o htab_erase.o

all:tail wordcount wordcount-dynamic libhtab.so libhtab.a

tail: tail.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) -static $^ -o $@

tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c -o tail.o

libhtab.a: $(OBJ)
	ar rcs $@ $^

libhtab.so: $(OBJ)
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $<

htab_begin.o: htab_begin.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_erase.o: htab_erase.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_bucket_count.o: htab_bucket_count.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_clear.o: htab_clear.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_end.o: htab_end.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_free.o: htab_free.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_hash_fun.o: htab_hash_fun.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_find.o: htab_find.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_init.o: htab_init.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_item_initialize.o: htab_item_initialize.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_iterator_get_key.o: htab_iterator_get_key.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_iterator_get_value.o: htab_iterator_get_value.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_iterator_initialize.o: htab_iterator_initialize.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_iterator_next.o: htab_iterator_next.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_iterator_set_value.o: htab_iterator_set_value.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_lookup_add.o: htab_lookup_add.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_move.o: htab_move.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

htab_size.o: htab_size.c $(HTAB_H)
	$(CC) $(CFLAGS) -fPIC -c $<

extern.o: extern.c htab.h
	$(CC) $(CFLAGS) -c -fPIC extern.c -o $@

clean:
	rm *.o tail wordcount wordcount-dynamic libhtab.so libhtab.a