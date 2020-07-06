//Subor: htab_find.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key) {
  
  size_t i = htab_hash_fun(key) % t->arr_size;
  struct htab_item * item = t->arr[i];

  htab_iterator_t it;

  if(!item) { //not found
    it = htab_end(t);
    return it;
  }

  else {
    
    it = htab_iterator_initialize(item, t, i);
    return it;
  }
}