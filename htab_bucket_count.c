//Subor: htab_bucket_count.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

size_t htab_bucket_count(const htab_t * t) {
  return t->arr_size;
}