//Subor: htab_lookup_add.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key){
   
  size_t i = htab_hash_fun(key) % t->arr_size;
  struct htab_item * item = t->arr[i];
  
  htab_iterator_t null_it = htab_iterator_initialize(NULL, t, i);
  htab_iterator_t it; 


  if(!item) { //item not existing

      item = htab_item_initialize(key); //we create it

      if(!item) { //init error

        return null_it;
      } 

      t->size++;
      t->arr[i] = item;
      
      it = htab_iterator_initialize(item, t, i);
      return it; //return the iterator
  }
  
  if(item->next != NULL) { //there is a next item

    for ( ;item->next != NULL; item = item->next) {  //
      
      if(strlen(item->key) == strlen(key)) {
        if (strcmp(key, item->key) == 0) {
            return htab_iterator_initialize(item, t, i);
        }
      }
    }
  }
  
  else {
    if(strlen(item->key) == strlen(key)) { //no sucessor
      if (strcmp(key, item->key) == 0) {
        return htab_iterator_initialize(item, t, i);
      }
    }
  }

  struct htab_item *temp = htab_item_initialize(key);

  if(!temp) {
    return null_it;
  }

  else {
    item->next = temp;
    t->size++;
    return htab_iterator_initialize(temp, t, i);
  } 
}

