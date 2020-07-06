//Subor: htab_hash_fun.c
//Autor: 
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include <stdint.h>
#include "htab.h"

size_t htab_hash_fun(const char *str) { //prevzate zo zadania
  uint32_t h=0;     // musí mít 32 bitů
  const unsigned char *p;
  for(p=(const unsigned char*)str; *p!='\0'; p++)
    h = 65599*h + *p;
  return h;
}