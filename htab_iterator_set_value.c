//Subor: htab_set_value.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {
    it.ptr->value = val;
    return val;
}