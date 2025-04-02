#include "emoji.h"



int main(int argc, char **argv) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }
  setlocale(LC_ALL, "");
  emojitable *table = create();
  for (size_t i = 0; i < strlen(argv[1]); i++) {
    const wchar_t res = emoji_get(table, &argv[1][i]);
    if (res == 0) {
      printf("%c", argv[1][i]);
    } else {
      printf("%lc", res);
    }
  }
  printf("\n");
  destroy(table);
  return EXIT_SUCCESS;
}