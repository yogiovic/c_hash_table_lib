//Subor: htab_free.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include <stdlib.h>
#include "htab.h"
#include "htab_structures.h"

void htab_free(htab_t * t) {
  htab_clear(t);
  free(t);
}
