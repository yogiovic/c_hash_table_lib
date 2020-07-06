//Subor: io.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 2
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include <stdlib.h>
#include "io.h"

int get_word(char *s, int max, FILE *f) {
  
  if (!f) {
    fprintf(stderr, "invalid file!\n");
    return EOF;
  }

  int c = 0;
  int i = 1; 
  
  while((c = fgetc(f)) != EOF && isspace(c)) {
    continue;
  } //skip spaces

  if (c == EOF) {
    return c;
  }

  s[0] = c;

  while(i < max - 1) {
    c = fgetc(f);
     if (isspace(c) || c == EOF) {
       break;
     }
     else {
       s[i++] = c;
     }
  }

  s[i] = '\0'; //;-)

  if (i == max - 1) {
    while((c = fgetc(f)) != EOF) {
      if(isspace(c)) {
        break;
      }
      else 
        i++;
    }
  }
  return i;
}