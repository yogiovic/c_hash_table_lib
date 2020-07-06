//Subor: htab_iterator_next.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it) {

  if (it.ptr->next) {
    it.ptr = it.ptr->next;
    return it;
  }

  size_t i;
  size_t max = it.t->arr_size;

  for (i = it.idx + 1; i < max; i++) { //find next
    if (it.t->arr[i]) {
      it.idx = i;
      it.ptr = it.t->arr[it.idx];
      return it;
    }
  }
  
  it.ptr = NULL; //next not found
  it.idx = it.t->arr_size;
  return it;
}