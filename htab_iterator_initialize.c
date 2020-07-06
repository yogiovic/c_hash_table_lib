//Subor: htab_iterator_initialize.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_iterator_t htab_iterator_initialize(struct htab_item * const ptr, const htab_t *t, const size_t idx) {
  
  htab_iterator_t i;

  i.t = t;
  i.ptr = ptr;
  i.idx = idx;
  
  return i;
}