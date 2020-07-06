//Subor: htab_end.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"


htab_iterator_t htab_end(const htab_t * t){
  htab_iterator_t it = htab_iterator_initialize(NULL, t, t->arr_size);
  return it;
}