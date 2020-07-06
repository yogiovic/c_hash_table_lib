//Subor: htab_item_initialize.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

struct htab_item * htab_item_initialize(htab_key_t key) {
  
  struct htab_item * temp = malloc(sizeof(struct htab_item));
  
  if(temp == NULL)
    return NULL;
  
  temp->next = NULL;
  temp->value = 0;

  temp->key = malloc(strlen(key) + 1); //+1 for the \0
  strcpy(temp->key, key);
  return temp;
}