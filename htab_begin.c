//Subor: htab_begin.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_iterator_t htab_begin(const htab_t * t) {

  size_t i;
  size_t max = t->arr_size;
  htab_iterator_t it;

  for(i = 0; i < max; i++) {
    if (t->arr[i]) { //!= NULL
      it = htab_iterator_initialize(t->arr[i], t, i); //return iterator
      return it;
    }

    else
      continue;
  }

  it = htab_iterator_initialize(NULL, t, 0);
  return it;
}