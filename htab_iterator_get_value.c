//Subor: htab_iterator_get_value.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include "htab.h"
#include "htab_structures.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it) {
    return it.ptr->value;
}