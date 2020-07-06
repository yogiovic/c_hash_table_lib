//Subor: htab_clear.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

void htab_clear(htab_t * t) {
  
  struct htab_item * item;
  struct htab_item * temp;

  size_t i;
  size_t max = t->arr_size;
  
  t->size = 0;

  for(i = 0; i < max; i++) {
    
    item = t->arr[i];

    while (item != NULL) { //we destroy the list
      temp = item;
      item = item->next;

      free(temp->key);
      free(temp);
    }

    t->arr[i] = NULL;
  }
}