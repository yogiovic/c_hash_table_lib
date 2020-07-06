//Subor: tail.c
//Autor: xondre12
//Fakulta: FIT VUT
//Uloha: 1
//Datum: 22.4.2020
//Prelozene: gcc 7.5.0

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct string {
  size_t length;
  size_t cap;
  char *s;
};

#define STRING_SIZE sizeof(struct string)

void error_exit(int code, const char *fmt, ...) {//IJC DU1
  va_list arguments;
  va_start(arguments, fmt);
  fprintf(stderr, "CHYBA: ");
  vfprintf(stderr, fmt, arguments);
  va_end(arguments);
  exit(code);
}


struct string * string_constructor() {
  
  struct string *str = malloc(STRING_SIZE);

  if (!str) {
    return NULL;
  }

  else {
    str->s = malloc(1024);
    str->length = 0;

    if(!str->s) {
      free(str);
      return NULL;
    }

    str->cap = 1024;
  }

  return str;
}

int string_resize(struct string *s) {

  size_t size = s->cap * 2;

  char *temp = realloc(s->s, size);

  if (!temp) {
    return EXIT_FAILURE; //error
  }

  else {
    s->cap = size;
    s->s = temp;
    return EXIT_SUCCESS;
  }
}

int string_append(struct string *str, const char c) {

  if (str->length + 1 >= str->cap) {
    if (string_resize(str) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }

  str->s[str->length] = c;
  str->length += 1;
  return EXIT_SUCCESS;
}

void string_free(struct string *str) {
  free(str->s);
  free(str);
}

struct string * load_lns(FILE *f) {

  struct string *str = string_constructor();
  
  if (!str) {
    return NULL;
  }

  int c; // = 0 ?
  for(    ;(c = fgetc(f)) != EOF;   ) {

    if(string_append(str, c) != EXIT_SUCCESS) { //!=0 -> TRUE
      string_free(str);
      return NULL;
    }
  }

  if (string_append(str, '\0') == EXIT_FAILURE) {
    string_free(str);
    return NULL;
  }
  return str;
}

size_t line_cnt(struct string *str) {
  
  size_t line_count = 0;
  size_t i = 0;
  
  while(str->s[i] != '\0') {
    
    if(str->s[i++] == '\n') { 
      line_count += 1;
    }
  }
  return line_count;
}

void print_tail(struct string *text, const size_t line_count, const size_t to_print) {

  if (to_print > line_count) {
    printf("%s", text->s);
  }

  else {

    size_t j = 0;
    size_t i = 0;
    while (i < line_count - to_print) {
      if(text->s[j++] == '\n') {
        i++;
      }
    }

    printf("%s", text->s+j);
  }

  return;
}

int main(int argc, char *argv[]) {

  FILE * f = stdin;
  struct string *text = NULL;

  size_t line_count = 0;
  size_t line_arg = 0;

  if (argc == 1) { //tail < subor
    text = load_lns(f);
    if(!text) {
      error_exit(EXIT_FAILURE, "malloc failed!\n");
    }

    else {
      line_count = line_cnt(text);
      print_tail(text, line_count, 10);
    }
  }
      
  else if (argc == 2) { //tail subor

    if (strcmp(argv[1], "-n") == 0) {
      error_exit(EXIT_FAILURE, "wrong arguments!\n");
    }

    f = fopen(argv[1], "r");
    
    if(!f) {
      error_exit(EXIT_FAILURE, "fopen error!\n");
    }

    text = load_lns(f);
    
    if (!text) {
      error_exit(EXIT_FAILURE, "malloc error!\n");
    }

    line_count = line_cnt(text);
    print_tail(text, line_count, 10);
  }

  else if (argc == 3) { //tail -n +3 < subor || tail -n 20 < subor
      
    if(strcmp(argv[1], "-n")) { //false -> zhoda
      error_exit(EXIT_FAILURE, "wrong arguments!\n");
    }

    line_arg = strtoul(argv[2], NULL, 10);
    text = load_lns(f);

    if (!text) {
      error_exit(EXIT_FAILURE, "malloc error!\n"); 
    }

    line_count = line_cnt(text);

    if (argv[2][0] == '+') { 
      size_t to_print_skip = line_count - line_arg + 1;
      print_tail(text, line_count, to_print_skip); //todo
    }
    else
      print_tail(text, line_count, line_arg);
    
  }

  else if (argc == 4) { //tail -n +3 subor || tail -n 20 subor

    if(strcmp(argv[1], "-n")) { //false -> zhoda
      error_exit(EXIT_FAILURE, "wrong arguments!\n");
    }

    f = fopen(argv[3], "r");

    if(!f) {
      error_exit(EXIT_FAILURE, "fopen error!\n"); 
    }

    line_arg = strtoul(argv[2], NULL, 10);
    text = load_lns(f);

    if (!text) {
      error_exit(EXIT_FAILURE, "malloc error!\n"); 
    }

    line_count = line_cnt(text);

    if (argv[2][0] == '+') { //prerobit na flag
      size_t to_print_skip = line_count - line_arg + 1;
      print_tail(text, line_count, to_print_skip); 
    }
    else
      print_tail(text, line_count, line_arg);

  }

  else {
    error_exit(EXIT_FAILURE, "wrong arguments!\n");
  }

  string_free(text);
  fclose(f);
  return EXIT_SUCCESS;
}