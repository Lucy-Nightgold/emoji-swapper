#include "emoji.h"

struct entrytable {
  char *key;
  wchar_t *value;
};


struct emojitable {
  entrytable *entries;
  size_t capacity;
  size_t length;
};

emojitable* create() {
  const wchar_t default_emoji[] = {0x1F34E, 0x1F354, 0x1F36B, 0x1F369, 0x1F95A, 0x1F33A, 0x1F370, 0x1FA93, 0xF33B,
  0x1F9C3, 0x1F428, 0x1F984, 0x1F96D, 0x1F303, 0x1F9C5, 0x1F95E, 0x1F986, 0x1F988, 0x1F96A, 0x1F685, 0x1F5F3, 0x26F5,
  0x1F9CA, 0x1F950, 0x1F957, 0x1F956};
  const size_t emojis_size = sizeof(default_emoji) / sizeof(default_emoji[0]);
  emojitable *table = malloc(sizeof(emojitable));
  if (table == NULL) {
    return NULL;
  }
  table->length = 0;
  table->capacity = 52;
  table->entries = malloc(sizeof(struct entrytable) * table->capacity);
  if (table->entries == NULL) {
    free(table);
    return NULL;
  }
  for (size_t i = 0; i < emojis_size && i < table->capacity; i++) {
    char key = (char) i + 97;
    table->entries[i].key = malloc(sizeof (char));
    *(table->entries[i].key) = key;
    table->entries[i].value = malloc(sizeof (wchar_t));
    *(table->entries[i].value) = default_emoji[i];
    table->length++;
  }
  return table;
}

void destroy(emojitable *table) {
  for (size_t i = 0; i < table->capacity; i++) {
    free(table->entries[i].key);
    free(table->entries[i].value);
  }
  free(table->entries);
  free(table);
}

wchar_t emoji_get(const emojitable *table, const char *char_to_swap) {
  for (size_t i = 0; i < table->length; i++) {
    if (*char_to_swap == *table->entries[i].key) {
      return *table->entries[i].value;
    }
  }
  return 0;
}