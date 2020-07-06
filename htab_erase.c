//Subor: htab_erase.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"
#include <stdio.h>

void htab_erase(htab_t * t, htab_iterator_t it) {
  
  if(t != NULL && it.ptr != NULL) {

    htab_iterator_t temp = htab_begin(t);
    htab_iterator_t pred = htab_begin(t);

    while(!htab_iterator_equal(temp, it)) {
      pred = temp;
      temp = htab_iterator_next(temp);
    }
    
    pred.ptr->next = it.ptr->next; //readjust the pointers

    free(it.ptr->key);
    free(it.ptr);
    t->arr[it.idx] = NULL; //erase

    it = htab_end(t); //iterator is no longer valid

  }
    return;
}