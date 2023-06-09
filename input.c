#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input(char *prompt) {
  if (prompt != NULL) {
    printf("%s", prompt);
  }

  int str_len = 1;
  char *str = malloc(str_len);

  for (char c; c != '\n' && c != EOF; c = getchar()) {
    str = realloc(str, ++str_len);
    strcat(str, (char[]){c});
  }

  str[str_len - 1] = '\0';

  char copy_str[strlen(str)];

  strcpy(copy_str, str);
  free(str);

  return (char *){copy_str};
}

int main(int argc, char *argv[]) {
  char *result = input("Input: ");
  printf("Your input was: %s\n", result);

  return 0;
}
