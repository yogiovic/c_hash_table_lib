//Subor: wordcount.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "htab.h"

#define HTAB_SIZE 62497 //"A good, short literary novel might be 62,000 words." + size should be prime 

int main(void) {   
  FILE *f = stdin;
  
  htab_t *table = htab_init(HTAB_SIZE);
  char *keystring = malloc(128);
  
  if (!keystring || !table) {
      fprintf(stderr, "Allocation failed.\n");
      return EXIT_FAILURE;
  }

  bool first_time = true;
  int word_len = 0;
  
  while((word_len = get_word(keystring, 128, f)) != EOF) {

    if(word_len >= 128) {
      if (first_time) {
        fprintf(stderr, "Error: word is too long\n"); 
        first_time = false;
      }
    }

      htab_iterator_t temp = htab_lookup_add(table, keystring);

      if(!htab_iterator_valid(temp)){
          free(keystring);
          htab_free(table); 
          return EXIT_FAILURE;
      }

      htab_value_t val = htab_iterator_get_value(temp);
      htab_iterator_set_value(temp, val+1);
  }

  htab_iterator_t i = htab_begin(table);
  htab_iterator_t end = htab_end(table);

  while (htab_iterator_equal(i, end) == false) {

    htab_key_t key = htab_iterator_get_key(i);
    htab_value_t val = htab_iterator_get_value(i);
    
    printf("%s\t%d\n", key, val);
    i = htab_iterator_next(i);
  }
  
  htab_free(table);
  free(keystring);
  return EXIT_SUCCESS;
}
