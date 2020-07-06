//Subor: extern.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"
#include <stdbool.h>

extern inline bool htab_iterator_valid(htab_iterator_t it);
extern inline bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2); 