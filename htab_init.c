//Subor: htab_init.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_t * htab_init(size_t n) {
  htab_t * t = malloc(sizeof(htab_t) + n * sizeof(struct htab_item));
  
  if (!t) {
    return NULL;
  }

  t->size = 0;
  t->arr_size = n;
  
  size_t i = 0;

  while(i < n) {
    t->arr[i++] = NULL;//initialize
  }
  
  return t;
}