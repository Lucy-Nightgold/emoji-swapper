#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdint.h>
#include <string.h>


typedef struct emojitable emojitable;
typedef struct entrytable entrytable;

emojitable* create();
void destroy(emojitable *table);
wchar_t emoji_get(const emojitable *table, const char *char_to_swap);
void set(emojitable *table, const char *char_to_swap, wchar_t *new_value);