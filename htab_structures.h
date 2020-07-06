//Subor: htab_structures.h
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#ifndef _HTAB_STRUCTURES_H_
#define _HTAB_STRUCTURES_H_

#include "htab.h"
#include <stdlib.h>

struct htab_item {
  int value;
  char * key;
  struct htab_item * next;
};

struct htab {
  size_t size;
  size_t arr_size;
  struct htab_item *arr[];
};

struct htab_item * htab_item_initialize(const char * key);

htab_iterator_t htab_iterator_initialize(struct htab_item * const ptr, const htab_t *t, const size_t idx);

#endif